# UT-2-SHA512.pro

QT += core testlib

TARGET = UT-2-SHA512
CONFIG += console
TEMPLATE = app

SOURCES += \
    main.cpp \
    sha512tests.cpp

HEADERS += \
    sha512tests.h

INCLUDEPATH += ../server
DEPENDPATH += ../server

LIBS += -lQt5Test
