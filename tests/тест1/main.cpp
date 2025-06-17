#include <QCoreApplication>
#include <QtTest>
#include "sha512tests.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Sha512Tests tests;
    return QTest::qExec(&tests);
}
