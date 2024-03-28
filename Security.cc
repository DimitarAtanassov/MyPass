#include "Security.hh"
#include <string>
#include <iostream>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/osrng.h>
Security::Security(const std::string& filePath)
{
    this->filePath = filePath;
}