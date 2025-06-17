QT += core
CONFIG += console c++17 qtestlib
TEMPLATE = app

TARGET = UT-2-SHA512

SOURCES += \
    main.cpp \
    sha512tests.cpp

HEADERS += \
    sha512tests.h

INCLUDEPATH += ../server
DEPENDPATH += ../server

# Для Qt 5
LIBS += -lQt5Test
