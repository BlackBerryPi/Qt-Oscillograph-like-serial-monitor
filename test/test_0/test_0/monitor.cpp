#include "monitor.h"
#include "ui_monitor.h"

#include <QDebug>

Monitor::Monitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Monitor)
{
    ui->setupUi(this);

    setWindowState(Qt::WindowMaximized);

    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
    {
        ui->comboBoxPort->addItem(info.portName());
    }

    setWindowTitle(tr("AttentivenessParameter"));
    ui->comboBoxPort->setFocus();

    connect(ui->buttonStart, &QPushButton::clicked, [=](){
        startSlave();
        //m_thread.shiftStatus();
    });
    connect(&m_thread, &SlaveThread::request, this,&Monitor::showRequest);
    connect(&m_thread, &SlaveThread::error, this, &Monitor::processError);
    connect(&m_thread, &SlaveThread::timeout, this, &Monitor::processTimeout);

    connect(ui->comboBoxPort, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
            this, &Monitor::activateRunButton);
    connect(ui->spinBoxBaudRate, QOverload<const QString &>::of(&QSpinBox::valueChanged),
            this, &Monitor::activateRunButton);
}

Monitor::~Monitor()
{
    delete ui;
}

void Monitor::startSlave()
{
    m_thread.shiftStatus();

    //ui->statusLabel->setText(tr("Status: Running, connected to port %1.").arg(ui->serialPortComboBox->currentText()));

    if(ui->comboBoxPort->currentText().compare("") == 0)
    {
        ui->textReceived->setText("端口号不可用!");
        return;
    }

    qDebug() << "run";
    if(m_thread.status())
    {
        ui->textReceived->setText("");
        m_thread.startSlave(ui->comboBoxPort->currentText(),ui->spinBoxBaudRate->value(),"a");
        ui->buttonStart->setText("关闭");
    }
    else
    {
        ui->buttonStart->setText("开启");
    }


}

void Monitor::showRequest(const QString &s)
{
    qDebug() << "Receives: " << s;
    ui->textReceived->append("0x"+s);
}

void Monitor::processError(const QString &s)
{
    activateRunButton();
//    ui->statusLabel->setText(tr("Status: Not running, %1.").arg(s));
//    ui->trafficLabel->setText(tr("No traffic."));
}

void Monitor::processTimeout(const QString &s)
{
//    ui->statusLabel->setText(tr("Status: Running, %1.").arg(s));
//    ui->trafficLabel->setText(tr("No traffic."));
}

void Monitor::activateRunButton()
{
//    ui->buttonStart->setEnabled(false);
//    ui->buttonStart->setText("停止");
}
