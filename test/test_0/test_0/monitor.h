#ifndef MONITOR_H
#define MONITOR_H

#include <QWidget>
#include <QMainWindow>
#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSerialPortInfo>
#include <QSpinBox>

#include "oscilloscope.h"
#include "slavethread.h"

namespace Ui {
class Monitor;
}

class Monitor : public QWidget
{
    Q_OBJECT

public:
    explicit Monitor(QWidget *parent = 0);
    ~Monitor();

private slots:
    void startSlave();
    void showRequest(const QString &s);
    void showRequestInt(const int &i);
    void processError(const QString &s);
    void processTimeout(const QString &s);
    void activateRunButton();

private:
    Ui::Monitor *ui;

    SlaveThread m_thread;

    int m_transactionCount = 0;
    int text_lines = 0;
};

#endif // MONITOR_H
