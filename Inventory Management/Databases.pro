#-------------------------------------------------
#
# Project created by QtCreator 2019-06-10T14:08:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Databases
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        add_item.cpp \
        delete_item.cpp \
        edit_item.cpp \
        in.cpp \
        main.cpp \
        mainwindow.cpp \
        out.cpp \
        search.cpp

HEADERS += \
        add_item.h \
        data.h \
        delete_item.h \
        edit_item.h \
        in.h \
        mainwindow.h \
        out.h \
        search.h

FORMS += \
        add_item.ui \
        delete_item.ui \
        edit_item.ui \
        in.ui \
        mainwindow.ui \
        out.ui \
        search.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

