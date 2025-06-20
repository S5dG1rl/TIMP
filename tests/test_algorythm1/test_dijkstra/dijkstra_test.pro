QT       += core
TARGET    = dijkstra_test
TEMPLATE  = app

# Источники
SOURCES += \
        dijkstra.cpp \
        test_dijkstra.cpp

# Подключаем заголовочные файлы
HEADERS += \
        dijkstra.h

# Настройки компиляции
CONFIG += c++17 console
CONFIG -= app_bundle

# Подключение Google Test
LIBS += -lgtest -lgtest_main -lpthread

# Для Windows, если используется MinGW:
# CONFIG += mingw_pkgconfig
# PKGCONFIG += gtest

# Если нужно указать путь к Qt (обычно не требуется):
# QT_DIR = C:/Qt/Tools/ming
