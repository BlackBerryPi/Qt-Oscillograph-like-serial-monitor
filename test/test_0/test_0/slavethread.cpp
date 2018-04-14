#include "slavethread.h"
#include "slavethread.h"
#include <QSerialPort>
#include <QTime>
#include <QDebug>

SlaveThread::SlaveThread(QObject *parent) :
    QThread(parent)
{
    m_quit = true;
}

//! [0]
SlaveThread::~SlaveThread()
{
    m_mutex.lock();
//    m_quit = true;
    m_mutex.unlock();
    wait();
}
//! [0]

//! [1] //! [2]
void SlaveThread::startSlave(const QString &portName, int waitTimeout, const QString &response)
{
    //! [1]
    const QMutexLocker locker(&m_mutex);
    m_portName = portName;
    m_waitTimeout = waitTimeout;
    m_response = response;

    //! [3]
    if (!isRunning())
    {
        emit this->request(QString("已连接\n端口号: %1\n波特率: %2\n").arg(portName).arg(waitTimeout));
        start();
    }
}

void SlaveThread::shiftStatus()
{
    m_quit = !m_quit;
}

bool SlaveThread::status()
{
    return !m_quit;
}

//! [2] //! [3]

//! [4]
void SlaveThread::run()
{
    bool currentPortNameChanged = false;

    m_mutex.lock();
//! [4] //! [5]
    QString currentPortName;
    if (currentPortName != m_portName) {
        currentPortName = m_portName;
        currentPortNameChanged = true;
    }

    int currentWaitTimeout = m_waitTimeout;
    QString currentRespone = m_response;
    m_mutex.unlock();
//! [5] //! [6]
    QSerialPort serial;

    serial.setDataBits(QSerialPort::Data8);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setReadBufferSize(1);

    while (!m_quit) {
//![6] //! [7]
        if (currentPortNameChanged) {
            serial.close();
            serial.setPortName(currentPortName);

            if (!serial.open(QIODevice::ReadWrite)) {
                emit error(tr("Can't open %1, error code %2")
                           .arg(m_portName).arg(serial.error()));
                return;
            }
        }

        if (serial.waitForReadyRead(currentWaitTimeout)) {
//! [7] //! [8]
            // read request
            QByteArray requestData = serial.readAll();
            while (serial.waitForReadyRead(10))
            {
//                requestData += serial.readAll();

                emit request(serial.readAll().toHex());
            }
//! [8] //! [10]
            // write response
            const QByteArray responseData = currentRespone.toUtf8();
            serial.write(responseData);
            if (serial.waitForBytesWritten(m_waitTimeout)) {
//                const QString request = QString::fromUtf8(requestData);
                const QString request = QString(requestData.toHex());
//! [12]
//                emit this->request(request);
//                qDebug() << "Request: " << request;
//! [10] //! [11] //! [12]
            } else {
                emit timeout(tr("Wait write response timeout %1")
                             .arg(QTime::currentTime().toString()));
            }
//! [9] //! [11]
        } else {
            emit timeout(tr("Wait read request timeout %1")
                         .arg(QTime::currentTime().toString()));
        }
//! [9]  //! [13]
        m_mutex.lock();
        if (currentPortName != m_portName) {
            currentPortName = m_portName;
            currentPortNameChanged = true;
        } else {
            currentPortNameChanged = false;
        }
        currentWaitTimeout = m_waitTimeout;
        currentRespone = m_response;
        m_mutex.unlock();
    }

    emit request("\n已断开");
//! [13]
}
