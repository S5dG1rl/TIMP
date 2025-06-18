#ifndef SHA512TESTS_H
#define SHA512TESTS_H

#include <QObject>

class Sha512Tests : public QObject
{
    Q_OBJECT
private slots:
    void test_sha512_emptyString();
    void test_sha512_simpleText();
};

#endif // SHA512TESTS_H
