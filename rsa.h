#ifndef RSA_H
#define RSA_H

#include <QString>
#include <QByteArray>
#include <string>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

/**
 * @brief Класс для RSA шифрования/дешифрования
 */
class RSAWrapper
{
public:
    /**
     * @brief Конструктор RSA
     * @param keySize Размер ключа в битах (по умолчанию 2048)
     */
    explicit RSAWrapper(int keySize = 2048);
    ~RSAWrapper();

    /**
     * @brief Зашифровать строку с использованием открытого ключа
     * @param plaintext Открытый текст
     * @return Зашифрованный текст в формате Base64
     */
    std::string encrypt(const std::string &plaintext);

    /**
     * @brief Расшифровать строку с использованием закрытого ключа
     * @param ciphertext Зашифрованный текст в формате Base64
     * @return Расшифрованный текст
     */
    std::string decrypt(const std::string &ciphertext);

    /**
     * @brief Получить открытый ключ в формате PEM
     * @return Строка с открытым ключом в формате PEM
     */
    std::string getPublicKey() const;

private:
    RSA* rsaKeyPair;
    std::string publicKeyPem;
    std::string privateKeyPem;
    
    void generateKeyPair(int keySize);
    std::string base64Encode(const unsigned char* input, int length);
    std::vector<unsigned char> base64Decode(const std::string &input);
};

#endif // RSA_H
