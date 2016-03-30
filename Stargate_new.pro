#-------------------------------------------------
#
# Project created by QtCreator 2015-06-10T19:30:49
#
#-------------------------------------------------

QT       += core gui svg serialport
CONFIG += qwt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Stargate_new
TEMPLATE = app
DESTDIR = ../bin
OBJECTS_DIR = ./obj
MOC_DIR = ./moc
RCC_DIR = ./rcc
UI_DIR = ./ui

INCLUDEPATH += ../Controller ../Calculations
LIBS += -L../lib -lController -lCalculations

INCLUDEPATH += ../seabreeze/include
LIBS += -L../seabreeze/lib -lseabreeze -lusb

INCLUDEPATH += ../qwt/build/include/
LIBS += ../qwt/build/lib/libqwt.a

SOURCES += main.cpp\
        mainwindow.cpp \
    measurementform.cpp \
    plotform.cpp \
    evaluateform.cpp \
    individualplotdialog.cpp \
    matrixform.cpp \
    matrixdialog.cpp \
    serviceform.cpp \
    exportdialog.cpp \
    motorsettingsform.cpp \
    spectrometerform.cpp \
    calculationform.cpp \
    calibrationform.cpp

HEADERS  += mainwindow.h \
    measurementform.h \
    plotform.h \
    evaluateform.h \
    individualplotdialog.h \
    matrixform.h \
    matrixdialog.h \
    serviceform.h \
    exportdialog.h \
    motorsettingsform.h \
    spectrometerform.h \
    calculationform.h \
    calibrationform.h

FORMS    += mainwindow.ui \
    measurementform.ui \
    plotform.ui \
    evaluateform.ui \
    individualplotdialog.ui \
    matrixform.ui \
    matrixdialog.ui \
    serviceform.ui \
    exportdialog.ui \
    motorsettingsform.ui \
    spectrometerform.ui \
    calculationform.ui \
    calibrationform.ui \
    measurementondialog.ui

RESOURCES += \
    Icons/Icons.qrc
