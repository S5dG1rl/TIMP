QT       += core testlib         # QtCore + QtTest
CONFIG   += console c++17 testcase
TEMPLATE  = app

SOURCES  += \
    main.cpp \
    sha512.cpp \
    sha512tests.cpp

HEADERS  += \
    sha512.h \
    sha512tests.h
