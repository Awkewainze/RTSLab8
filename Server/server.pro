#-------------------------------------------------
#
# Project created by QtCreator 2016-04-22T13:54:28
#
#-------------------------------------------------

QT       += core gui
QT += printsupport

QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS += -lasound

LIBS = -lasound

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app

SOURCES += main.cpp\
    AudioPlayer.cpp \
    VideoPlayer.cpp \
    Player.cpp \
    NetworkListener.cpp \
    AudioInterface.cpp

HEADERS  += \
    AudioPlayer.h \
    VideoPlayer.h \
    Player.h \
    NetworkListener.h \
    AudioInterface.h
