/********************************************************************************
** Form generated from reading UI file 'monitor.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITOR_H
#define UI_MONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <oscilloscope.h>

QT_BEGIN_NAMESPACE

class Ui_Monitor
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBoxPort;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QSpinBox *spinBoxBaudRate;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonStart;
    QTabWidget *tabWidget;
    QWidget *tabText;
    QGridLayout *gridLayout_2;
    QTextEdit *textReceived;
    QWidget *tabMonitor;
    QGridLayout *gridLayout_3;
    Oscilloscope *widget;
    QSpacerItem *verticalSpacer;
    QDial *dialXStrech;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    QDial *dialXMove;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_3;
    QDial *dialYStrech;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_4;
    QDial *dialYMove;
    QLabel *label_6;

    void setupUi(QWidget *Monitor)
    {
        if (Monitor->objectName().isEmpty())
            Monitor->setObjectName(QStringLiteral("Monitor"));
        Monitor->setWindowModality(Qt::NonModal);
        Monitor->setEnabled(true);
        Monitor->resize(1000, 618);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Monitor->sizePolicy().hasHeightForWidth());
        Monitor->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        Monitor->setFont(font);
        Monitor->setAutoFillBackground(true);
        gridLayout = new QGridLayout(Monitor);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Monitor);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBoxPort = new QComboBox(Monitor);
        comboBoxPort->setObjectName(QStringLiteral("comboBoxPort"));

        gridLayout->addWidget(comboBoxPort, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label_2 = new QLabel(Monitor);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        spinBoxBaudRate = new QSpinBox(Monitor);
        spinBoxBaudRate->setObjectName(QStringLiteral("spinBoxBaudRate"));
        spinBoxBaudRate->setMaximum(115200);
        spinBoxBaudRate->setValue(9600);
        spinBoxBaudRate->setDisplayIntegerBase(10);

        gridLayout->addWidget(spinBoxBaudRate, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(1120, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 5, 1, 1);

        buttonStart = new QPushButton(Monitor);
        buttonStart->setObjectName(QStringLiteral("buttonStart"));

        gridLayout->addWidget(buttonStart, 0, 6, 1, 1);

        tabWidget = new QTabWidget(Monitor);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabText = new QWidget();
        tabText->setObjectName(QStringLiteral("tabText"));
        gridLayout_2 = new QGridLayout(tabText);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        textReceived = new QTextEdit(tabText);
        textReceived->setObjectName(QStringLiteral("textReceived"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textReceived->sizePolicy().hasHeightForWidth());
        textReceived->setSizePolicy(sizePolicy1);
        textReceived->setAutoFillBackground(false);
        textReceived->setReadOnly(true);

        gridLayout_2->addWidget(textReceived, 0, 0, 1, 1);

        tabWidget->addTab(tabText, QString());
        tabMonitor = new QWidget();
        tabMonitor->setObjectName(QStringLiteral("tabMonitor"));
        gridLayout_3 = new QGridLayout(tabMonitor);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new Oscilloscope(tabMonitor);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(widget, 0, 0, 1, 1);

        tabWidget->addTab(tabMonitor, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 12, 6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 6, 1, 1);

        dialXStrech = new QDial(Monitor);
        dialXStrech->setObjectName(QStringLiteral("dialXStrech"));
        dialXStrech->setWrapping(true);
        dialXStrech->setNotchesVisible(false);

        gridLayout->addWidget(dialXStrech, 2, 6, 1, 1);

        label_3 = new QLabel(Monitor);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(16777215, 20));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 3, 6, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 6, 1, 1);

        dialXMove = new QDial(Monitor);
        dialXMove->setObjectName(QStringLiteral("dialXMove"));
        dialXMove->setWrapping(true);

        gridLayout->addWidget(dialXMove, 5, 6, 1, 1);

        label_4 = new QLabel(Monitor);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(16777215, 20));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 6, 6, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 7, 6, 1, 1);

        dialYStrech = new QDial(Monitor);
        dialYStrech->setObjectName(QStringLiteral("dialYStrech"));
        dialYStrech->setWrapping(true);

        gridLayout->addWidget(dialYStrech, 8, 6, 1, 1);

        label_5 = new QLabel(Monitor);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(16777215, 20));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 9, 6, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 10, 6, 1, 1);

        dialYMove = new QDial(Monitor);
        dialYMove->setObjectName(QStringLiteral("dialYMove"));
        dialYMove->setWrapping(true);
        dialYMove->setNotchesVisible(false);

        gridLayout->addWidget(dialYMove, 11, 6, 1, 1);

        label_6 = new QLabel(Monitor);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(16777215, 20));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 12, 6, 1, 1);


        retranslateUi(Monitor);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Monitor);
    } // setupUi

    void retranslateUi(QWidget *Monitor)
    {
        Monitor->setWindowTitle(QApplication::translate("Monitor", "Monitor", nullptr));
        label->setText(QApplication::translate("Monitor", "\347\253\257\345\217\243\345\217\267", nullptr));
        label_2->setText(QApplication::translate("Monitor", "\346\263\242\347\211\271\347\216\207", nullptr));
        spinBoxBaudRate->setPrefix(QString());
        buttonStart->setText(QApplication::translate("Monitor", "\345\274\200\345\220\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabText), QApplication::translate("Monitor", "\347\233\221\350\247\206\345\231\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabMonitor), QApplication::translate("Monitor", "\347\273\230\345\233\276\345\231\250", nullptr));
        label_3->setText(QApplication::translate("Monitor", "X\350\275\264\346\213\211\344\274\270", nullptr));
        label_4->setText(QApplication::translate("Monitor", "X\350\275\264\345\271\263\347\247\273", nullptr));
        label_5->setText(QApplication::translate("Monitor", "Y\350\275\264\346\213\211\344\274\270", nullptr));
        label_6->setText(QApplication::translate("Monitor", "Y\350\275\264\345\271\263\347\247\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Monitor: public Ui_Monitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITOR_H
