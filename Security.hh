#ifndef SECURITY_H
#define SECURITY_H
#include <string>
#include <iostream>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/secblock.h>
#include <cryptopp/osrng.h>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/cryptlib.h>
class Security
{
    public:
        Security();
        CryptoPP::SecByteBlock GenerateRandomKey(unsigned int keySize);
        CryptoPP::SecByteBlock DeriveKeyFromPassword(const std::string& password, const CryptoPP::byte* salt, size_t saltSize, unsigned int keySize);
        void EncryptPasswordFile(const std::string& inputFilename, const std::string& outputFilename, const  CryptoPP::SecByteBlock& key);
        void DecryptPasswordFile(const std::string& inputFilename, const std::string& outputFilename, const  CryptoPP::SecByteBlock& key);
    private:
       
};

#endif
