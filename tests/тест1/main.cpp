#include <QCoreApplication>
#include <QtTest>

#include "sha512tests.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    Sha512Tests tests;
    int result = QTest::qExec(&tests, argc, argv);
    return result;
}
