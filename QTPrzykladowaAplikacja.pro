#-------------------------------------------------
#
# Project created by QtCreator 2019-04-09T18:38:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTPrzykladowaAplikacja
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    przyklady.cpp \
    bazydanych.cpp

LIBS += -lsqlite3

HEADERS  += mainwindow.h \
    przyklady.h \
    bazydanych.h

FORMS    += mainwindow.ui
