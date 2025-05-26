QT -= gui
QT += core
QT += network
QT += sql

CONFIG += c++11 console
CONFIG -= app_bundle

# For macOS with Homebrew OpenSSL
INCLUDEPATH += /opt/homebrew/opt/openssl@3/include
LIBS += -L/opt/homebrew/opt/openssl@3/lib -lssl -lcrypto

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    rsa.cpp \
    dichotomymethod.cpp \
    database.cpp \
    dijkstra.cpp \
    functionsforserver.cpp \
    main.cpp \
    sha512.cpp \
    tcpserver.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    rsa.h \
    dichotomymethod.h \
    database.h \
    dijkstra.h \
    functionsforserver.h \
    sha512.h \
    tcpserver.h





