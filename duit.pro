#-------------------------------------------------
#
# Project created by QtCreator 2016-04-19T12:29:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++14
TARGET = duit
TEMPLATE = app


SOURCES += main.cpp\
        duit.cpp \
    eventsmodel.cpp \
    scheduledevent.cpp

HEADERS  += duit.h \
    eventsmodel.h \
    scheduledevent.h

FORMS    += duit.ui
