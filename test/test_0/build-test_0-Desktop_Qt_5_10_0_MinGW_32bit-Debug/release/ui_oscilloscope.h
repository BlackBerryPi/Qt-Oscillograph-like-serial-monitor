/********************************************************************************
** Form generated from reading UI file 'oscilloscope.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSCILLOSCOPE_H
#define UI_OSCILLOSCOPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Oscilloscope
{
public:

    void setupUi(QWidget *Oscilloscope)
    {
        if (Oscilloscope->objectName().isEmpty())
            Oscilloscope->setObjectName(QStringLiteral("Oscilloscope"));
        Oscilloscope->resize(848, 646);

        retranslateUi(Oscilloscope);

        QMetaObject::connectSlotsByName(Oscilloscope);
    } // setupUi

    void retranslateUi(QWidget *Oscilloscope)
    {
        Oscilloscope->setWindowTitle(QApplication::translate("Oscilloscope", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Oscilloscope: public Ui_Oscilloscope {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSCILLOSCOPE_H
