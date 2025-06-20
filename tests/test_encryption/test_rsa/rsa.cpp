#include "rsa.h"
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include <stdexcept>
#include <sstream>

RSAWrapper::RSAWrapper(int keySize) {
    OpenSSL_add_all_algorithms();
    generateKeyPair(keySize);
}

RSAWrapper::~RSAWrapper() {
    if (rsaKeyPair) {
        RSA_free(rsaKeyPair);
    }
    EVP_cleanup();
}

void RSAWrapper::generateKeyPair(int keySize) {
    // Генерация ключевой пары
    BIGNUM* bne = BN_new();
    if (!BN_set_word(bne, RSA_F4)) {
        BN_free(bne);
        throw std::runtime_error("Failed to set RSA exponent");
    }

    rsaKeyPair = RSA_new();
    if (!RSA_generate_key_ex(rsaKeyPair, keySize, bne, nullptr)) {
        RSA_free(rsaKeyPair);
        BN_free(bne);
        throw std::runtime_error("Failed to generate RSA key pair");
    }
    BN_free(bne);

    // Сохранение открытого ключа в формате PEM
    BIO* pub = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPublicKey(pub, rsaKeyPair);

    BUF_MEM* pubKeyPtr;
    BIO_get_mem_ptr(pub, &pubKeyPtr);
    publicKeyPem = std::string(pubKeyPtr->data, pubKeyPtr->length);
    BIO_free(pub);
}

std::string RSAWrapper::encrypt(const std::string& plaintext) {
    if (plaintext.empty()) {
        return "";
    }

    int rsaLen = RSA_size(rsaKeyPair);
    std::vector<unsigned char> encrypted(rsaLen);

    int result = RSA_public_encrypt(
        plaintext.length(),
        reinterpret_cast<const unsigned char*>(plaintext.c_str()),
        encrypted.data(),
        rsaKeyPair,
        RSA_PKCS1_OAEP_PADDING
    );

    if (result == -1) {
        throw std::runtime_error("Encryption failed");
    }

    return base64Encode(encrypted.data(), result);
}

std::string RSAWrapper::decrypt(const std::string& ciphertext) {
    if (ciphertext.empty()) {
        return "";
    }

    auto encrypted = base64Decode(ciphertext);
    int rsaLen = RSA_size(rsaKeyPair);
    std::vector<unsigned char> decrypted(rsaLen);

    int result = RSA_private_decrypt(
        encrypted.size(),
        encrypted.data(),
        decrypted.data(),
        rsaKeyPair,
        RSA_PKCS1_OAEP_PADDING
    );

    if (result == -1) {
        throw std::runtime_error("Decryption failed");
    }

    return std::string(decrypted.begin(), decrypted.begin() + result);
}

std::string RSAWrapper::getPublicKey() const {
    return publicKeyPem;
}

std::string RSAWrapper::base64Encode(const unsigned char* input, int length) {
    BIO* bio, * b64;
    BUF_MEM* bufferPtr;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);
    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);

    BIO_write(bio, input, length);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);

    std::string encoded(bufferPtr->data, bufferPtr->length);

    BIO_free_all(bio);

    return encoded;
}

std::vector<unsigned char> RSAWrapper::base64Decode(const std::string& input) {
    BIO* bio, * b64;

    int decodeLen = input.length();
    std::vector<unsigned char> buffer(decodeLen);

    b64 = BIO_new(BIO_f_base64());
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    bio = BIO_new_mem_buf(input.c_str(), -1);
    bio = BIO_push(b64, bio);

    int length = BIO_read(bio, buffer.data(), decodeLen);
    BIO_free_all(bio);

    if (length <= 0) {
        throw std::runtime_error("Base64 decode failed");
    }

    buffer.resize(length);
    return buffer;
}
