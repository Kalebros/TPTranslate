#-------------------------------------------------
#
# Project created by QtCreator 2016-06-08T22:32:37
#
#-------------------------------------------------

QT       -= gui

CONFIG+= c++11

TARGET = TPFile
TEMPLATE = lib
CONFIG += staticlib

DESTDIR = ../lib

LIBS += -lgdal

SOURCES += tpfile.cpp

HEADERS += tpfile.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
