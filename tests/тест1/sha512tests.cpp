#include "sha512tests.h"
#include "sha512.h"
#include <QtTest/QtTest>

void Sha512Tests::test_sha512_emptyString()
{
    const std::string expected =
        "cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc"
        "83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f"
        "63b931bd47417a81a538327af927da3e";

    QCOMPARE(sha512(""), expected);
}

void Sha512Tests::test_sha512_simpleText()
{
    const std::string expected =
        "9b71d224bd62f3785d96d46ad3ea3d73319bfbc2890caada"
        "e2dff72519673ca72323c3d99ba5c11d7c7acc6e14b8c5da"
        "0c4663475c2e5c3adef46f73bcdec043";

    QCOMPARE(sha512("hello"), expected);
}
