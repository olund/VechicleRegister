#-------------------------------------------------
#
# Project created by QtCreator 2015-04-21T19:59:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VehicleRegister
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    vehicle.cpp \
    boat.cpp \
    motorcycle.cpp \
    sailboat.cpp \
    addvehicle.cpp \
    addsomething.cpp \
    register.cpp \
    trike.cpp \
    addtrike.cpp \
    addsailboat.cpp \
    edit.cpp

HEADERS  += mainwindow.h \
    vehicle.h \
    boat.h \
    motorcycle.h \
    myvector.h \
    reader.h \
    sailboat.h \
    addvehicle.h \
    addsomething.h \
    register.h \
    filehandler.h \
    trike.h \
    addtrike.h \
    addsailboat.h \
    edit.h

FORMS    += mainwindow.ui \
    addvehicle.ui \
    addsomething.ui \
    addtrike.ui \
    addsailboat.ui \
    edit.ui


QMAKE_CXXFLAGS += -std=c++11

DISTFILES += \
    New Text Document.txt
