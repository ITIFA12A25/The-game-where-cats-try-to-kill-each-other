#include "startingwindow.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    startingWindow w;
    w.show();
    return a.exec();
}
