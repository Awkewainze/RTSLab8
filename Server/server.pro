#-------------------------------------------------
#
# Project created by QtCreator 2016-04-22T13:54:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
    AudioPlayer.cpp \
    VideoPlayer.cpp \
    Player.cpp \
    NetworkListener.cpp

HEADERS  += \
    AudioPlayer.h \
    VideoPlayer.h \
    Player.h \
    NetworkListener.h
