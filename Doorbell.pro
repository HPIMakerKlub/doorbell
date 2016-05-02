QT += core
QT += websockets
QT += multimedia
QT -= gui

CONFIG += c++11

TARGET = Doorbell
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    doorbell.cpp

HEADERS += \
    doorbell.h
