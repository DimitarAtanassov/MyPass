#ifndef SECURITY_H
#define SECURITY_H
#include string
#include <iostream>
class SECURITY_H
{
    public:
        Security(const std::string&)
        std::string encrypt();
        std::string decrypt();
        void encryptFile();
        void decryptFile();
    private:
        std::string filePath;
}

#endif
