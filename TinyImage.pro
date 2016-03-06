#-------------------------------------------------
#
# Project created by QtCreator 2016-03-05T17:24:08
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TinyImage
TEMPLATE = app


SOURCES += main.cpp \
    window.cpp \
    uploadslot.cpp \
    downloadslot.cpp

HEADERS  += \
    window.h \
    uploadslot.h \
    downloadslot.h
