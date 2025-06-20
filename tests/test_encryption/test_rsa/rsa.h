#ifndef RSA_H
#define RSA_H

#include <QString>
#include <QByteArray>
#include <string>
#include <vector>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

/**
 * @brief ����� ��� RSA ����������/������������
 */
class RSAWrapper
{
public:
    /**
     * @brief ����������� RSA
     * @param keySize ������ ����� � ����� (�� ��������� 2048)
     */
    explicit RSAWrapper(int keySize = 2048);
    ~RSAWrapper();

    /**
     * @brief ����������� ������ � �������������� ��������� �����
     * @param plaintext �������� �����
     * @return ������������� ����� � ������� Base64
     */
    std::string encrypt(const std::string& plaintext);

    /**
     * @brief ������������ ������ � �������������� ��������� �����
     * @param ciphertext ������������� ����� � ������� Base64
     * @return �������������� �����
     */
    std::string decrypt(const std::string& ciphertext);

    /**
     * @brief �������� �������� ���� � ������� PEM
     * @return ������ � �������� ������ � ������� PEM
     */
    std::string getPublicKey() const;

private:
    RSA* rsaKeyPair;
    std::string publicKeyPem;
    std::string privateKeyPem;

    void generateKeyPair(int keySize);
    std::string base64Encode(const unsigned char* input, int length);
    std::vector<unsigned char> base64Decode(const std::string& input);
};

#endif // RSA_H
