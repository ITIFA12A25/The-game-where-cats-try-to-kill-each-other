QT       += core gui
QT += quick
QT += quickcontrols2

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    gamewindow.cpp \
    infopopupwindow.cpp \
    main.cpp \
    selectionwindow.cpp \
    startingwindow.cpp \
    winwindow.cpp

HEADERS += \
    client.h \
    gamewindow.h \
    infopopupwindow.h \
    selectionwindow.h \
    startingwindow.h \
    winwindow.h

FORMS += \
    gamewindow.ui \
    infopopupwindow.ui \
    selectionwindow.ui \
    startingwindow.ui \
    winwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
