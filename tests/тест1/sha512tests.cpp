#include "sha512tests.h"
#include <QtTest>
#include "../server/sha512.h"

void Sha512Tests::test_sha512_emptyString()
{
    std::string input = "";
    std::string expected_hash = "cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e";
    std::string actual_hash = sha512(input);
    QCOMPARE(QString::fromStdString(actual_hash), QString::fromStdString(expected_hash));
}

void Sha512Tests::test_sha512_simpleText()
{
    std::string input = "hello";
    std::string expected_hash = "9b71d224bd62f37fffd86e1eeaf70b1aae4a79735cd0001f9be4c8cadae9b1f771de89e252fd861e1410926ffd86e8d80a7f2ed2ed569ba648c2f54a80f9a8fbcab08636f753846b0e0d1340ca978bc5e1250211182a708d545a435d89c02817998d83d42cb251052862305606720809376c00c2f662d4ddd8c30cc5defd1bf24413a5edfc5a8801fc3546362e3533e71a6120c935d89da5c1f0f9717ec0ad9d6c6594f1f9d2e5afa88d8c5953e3d3400487bf60be0e3702eb179c22590192e8462eeebfb4480342a2b174fc3fa6ada3a241fa8f3a101204952eeee00014486735609048fc7ddf990c779e765b4dcad993cf9fab09e86221a9f80a9912512f72e32ea5df21f1a6d943521ff7db2eadfdf8f9ea5023165b92386c00a22739810b0e4e0291206e90409019487659692fe77104dd0954da70640cd8ac74d3e1297e586002a326a3";

    std::string actual_hash = sha512(input);

    QCOMPARE(QString::fromStdString(actual_hash), QString::fromStdString(expected_hash));
}
