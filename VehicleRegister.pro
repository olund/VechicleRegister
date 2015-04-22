#-------------------------------------------------
#
# Project created by QtCreator 2015-04-21T19:59:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VehicleRegister
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vehicle.cpp \
    boat.cpp \
    motorcycle.cpp \
    sailboat.cpp

HEADERS  += mainwindow.h \
    vehicle.h \
    boat.h \
    motorcycle.h \
    myvector.h \
    reader.h \
    sailboat.h

FORMS    += mainwindow.ui


QMAKE_CXXFLAGS += -std=c++11
