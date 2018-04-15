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
    void startSlave();                                          //启动串口线程
    void showRequest(const QString &s);                         //显示串口线程传回的字符串信息
    void showRequestInt(const int &i);                          //显示串口线程传回的数值信息
    void processError(const QString &s);                        //串口报错
    void processTimeout(const QString &s);                      //串口超时
    void activateRunButton();                                   //启动时改变按钮文字

    void on_dialXStrech_valueChanged(int value);

signals:
    void resolutionChanged(int x_str, int y_str, int x_move, int y_move);   //设置分辨率和偏移值

private:
    Ui::Monitor *ui;

    SlaveThread m_thread;                                       //串口线程

    int m_prev_dialXStrech = 0;                                 //初始X拉伸
    int m_prev_dialYStrech = 0;                                 //初始Y拉伸
    int m_prev_dialXMove = 0;                                   //初始X平移
    int m_prev_dialYMove = 0;                                   //初始Y平移

    int m_transactionCount = 0;
};

#endif // MONITOR_H
