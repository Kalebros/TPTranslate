#-------------------------------------------------
#
# Project created by QtCreator 2016-06-14T15:49:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = App
TEMPLATE = app

INCLUDEPATH+= ..
LIBS += -L../lib -lgdal -lTPFile


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
