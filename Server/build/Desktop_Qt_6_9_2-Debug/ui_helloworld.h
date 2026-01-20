/********************************************************************************
** Form generated from reading UI file 'helloworld.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLOWORLD_H
#define UI_HELLOWORLD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helloworld
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *helloworld)
    {
        if (helloworld->objectName().isEmpty())
            helloworld->setObjectName("helloworld");
        helloworld->resize(800, 600);
        centralwidget = new QWidget(helloworld);
        centralwidget->setObjectName("centralwidget");
        helloworld->setCentralWidget(centralwidget);
        menubar = new QMenuBar(helloworld);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        helloworld->setMenuBar(menubar);
        statusbar = new QStatusBar(helloworld);
        statusbar->setObjectName("statusbar");
        helloworld->setStatusBar(statusbar);

        retranslateUi(helloworld);

        QMetaObject::connectSlotsByName(helloworld);
    } // setupUi

    void retranslateUi(QMainWindow *helloworld)
    {
        helloworld->setWindowTitle(QCoreApplication::translate("helloworld", "helloworld", nullptr));
    } // retranslateUi

};

namespace Ui {
    class helloworld: public Ui_helloworld {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOWORLD_H
