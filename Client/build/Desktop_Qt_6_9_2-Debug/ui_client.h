/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_client
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuThe_Game_Where_Cats_Try_To_Kill_Each_Other;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *client)
    {
        if (client->objectName().isEmpty())
            client->setObjectName("client");
        client->resize(800, 600);
        centralwidget = new QWidget(client);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 200, 111, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(300, 200, 111, 41));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(480, 200, 111, 41));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 50, 601, 101));
        client->setCentralWidget(centralwidget);
        menubar = new QMenuBar(client);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuThe_Game_Where_Cats_Try_To_Kill_Each_Other = new QMenu(menubar);
        menuThe_Game_Where_Cats_Try_To_Kill_Each_Other->setObjectName("menuThe_Game_Where_Cats_Try_To_Kill_Each_Other");
        client->setMenuBar(menubar);
        statusbar = new QStatusBar(client);
        statusbar->setObjectName("statusbar");
        client->setStatusBar(statusbar);

        menubar->addAction(menuThe_Game_Where_Cats_Try_To_Kill_Each_Other->menuAction());

        retranslateUi(client);

        QMetaObject::connectSlotsByName(client);
    } // setupUi

    void retranslateUi(QMainWindow *client)
    {
        client->setWindowTitle(QCoreApplication::translate("client", "client", nullptr));
        pushButton->setText(QCoreApplication::translate("client", "Replay", nullptr));
        pushButton_2->setText(QCoreApplication::translate("client", "Play", nullptr));
        pushButton_3->setText(QCoreApplication::translate("client", "Info", nullptr));
        label->setText(QCoreApplication::translate("client", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:700;\">The Game Where Cats Try To Kill Each Other</span></p></body></html>", nullptr));
        menuThe_Game_Where_Cats_Try_To_Kill_Each_Other->setTitle(QCoreApplication::translate("client", "The Game Where Cats Try To Kill Each Other", nullptr));
    } // retranslateUi

};

namespace Ui {
    class client: public Ui_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
