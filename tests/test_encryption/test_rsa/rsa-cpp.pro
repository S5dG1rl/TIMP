QT       += core
TARGET   = rsa_tests
TEMPLATE = app

# Источники
SOURCES += \
        src/rsa.cpp \
        test/rsa_test.cpp

INCLUDEPATH += include

# Подключение OpenSSL
LIBS += -lssl -lcrypto

# GTest
LIBS += -lgtest -lgtest_main -lpthread

# Указываем, что это тестовый проект
CONFIG += console
CONFIG -= app_bundle

# Для C++17
QMAKE_CXXFLAGS += -std=c++17
