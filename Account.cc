#include "Account.hh"

Account::Account(const std::string& source, const std::string& username, const std::string& password, const std::string& email)
{
    this->source = source;
    this->username = username;
    this->password = password;
    this->email = email;
}

// Getters

std::string Account::getSource()
{
    return this->source;
} 

std::string Account::getUsername()
{
    return this->username;
}

std::string Account::getPassword()
{
    return this->password;
}

std::string Account::getEmail()
{
    return this->email;
}

// Setters

void Account::setSource(const std::string& newSource)
{
    this->source = newSource;
}

void Account::setUsername(const std::string& newUsername)
{
    this->username = newUsername;
}

void Account::setPassword(const std::string& newPassword)
{
    this->password = newPassword;
}

void Account::setEmail(const std::string& newEmail)
{
    this->email = newEmail;
}