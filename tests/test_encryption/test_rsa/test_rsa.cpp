#include "rsa.h"
#include <iostream>
#include <cassert>

void runTests() {
    std::cout << "=== Запуск тестов RSA ===" << std::endl;

    // Тест 1: Шифрование и дешифрование строки
    {
        RSAWrapper rsa;
        std::string original = "Hello, World!";
        std::string encrypted = rsa.encrypt(original);
        std::string decrypted = rsa.decrypt(encrypted);

        assert(original == decrypted);
        std::cout << "Тест 1 пройден: шифрование/дешифрование работает корректно." << std::endl;
    }

    // Тест 2: Пустая строка
    {
        RSAWrapper rsa;
        std::string original = "";
        std::string encrypted = rsa.encrypt(original);
        std::string decrypted = rsa.decrypt(encrypted);

        assert(original == decrypted);
        std::cout << "Тест 2 пройден: обработка пустой строки работает корректно." << std::endl;
    }

    // Тест 3: Получение открытого ключа (проверка не критична, но можно проверить на наличие "BEGIN PUBLIC KEY")
    {
        RSAWrapper rsa;
        std::string publicKey = rsa.getPublicKey();
        assert(publicKey.find("-----BEGIN PUBLIC KEY-----") != std::string::npos);
        std::cout << "Тест 3 пройден: формат открытого ключа верен." << std::endl;
    }

    std::cout << "=== Все тесты успешно пройдены! ===" << std::endl;
}

int main() {
    runTests();
    return 0;
}