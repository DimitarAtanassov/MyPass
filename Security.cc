#include "Security.hh"
#include <iostream>
#include <string>
#include <fstream>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/secblock.h>
#include <cryptopp/osrng.h>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/pwdbased.h>
#include <cryptopp/files.h>
using namespace CryptoPP;

// Function to generate a random encryption key
SecByteBlock Security::GenerateRandomKey(unsigned int keySize) {
    AutoSeededRandomPool prng;
    SecByteBlock key(keySize);
    prng.GenerateBlock(key, keySize);
    return key;
}

// Function to derive an encryption key from a user's password using PBKDF2
SecByteBlock Security::DeriveKeyFromPassword(const std::string& password, const byte* salt, size_t saltSize, unsigned int keySize) {
    SecByteBlock derivedKey(keySize);
    CryptoPP::PKCS5_PBKDF2_HMAC<CryptoPP::SHA256> pbkdf2;
    pbkdf2.DeriveKey(derivedKey, derivedKey.size(), 0x00, (byte*)password.data(), password.size(), salt, saltSize, 1000); // 1000 iterations
    return derivedKey;
}

// Function to encrypt the password file using AES encryption
void Security::EncryptPasswordFile(const std::string& inputFilename, const std::string& outputFilename, const SecByteBlock& key) {
    CBC_Mode<AES>::Encryption encryptor;
    encryptor.SetKeyWithIV(key, AES::DEFAULT_KEYLENGTH, (const byte*)"\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0A\x0B\x0C\x0D\x0E\x0F"); // IV

    std::ifstream inputFile(inputFilename, std::ios::binary);
    std::ofstream outputFile(outputFilename, std::ios::binary);

    // Encrypt the file
    FileSource(inputFile, true, new StreamTransformationFilter(encryptor, new FileSink(outputFile)));
}

// Function to decrypt the password file using AES decryption
void Security::DecryptPasswordFile(const std::string& inputFilename, const std::string& outputFilename, const SecByteBlock& key) {
    CBC_Mode<AES>::Decryption decryptor;
    decryptor.SetKeyWithIV(key, AES::DEFAULT_KEYLENGTH, (const byte*)"\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0A\x0B\x0C\x0D\x0E\x0F"); // IV

    std::ifstream inputFile(inputFilename, std::ios::binary);
    std::ofstream outputFile(outputFilename, std::ios::binary);

    // Decrypt the file
    FileSource(inputFile, true, new StreamTransformationFilter(decryptor, new FileSink(outputFile)));
}



Security::Security()
{
    
}