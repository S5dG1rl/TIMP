#include <QCoreApplication>
#include <QtTest/QtTest>
#include "sha512tests.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    Sha512Tests tc;
    return QTest::qExec(&tc, argc, argv);
}
