#include "PasswordManger.hh"

std::string PasswordManager::getPassword(const std::string& source)
{

}


Account PasswordManager::addPassword()
{
    std::string newSource; 
    std::string newUsername;
    std::string newPassword;
    std::string newEmail;
    
    std::cout << "Where is this password used?" << std::endl;
    std:: cin >> newSource;

    std::cout << "What is the username linked to this password? If there is none press just press enter." << std::endl;
    std::cin >> newUsername;

    std::cout << "What is the password?" << std::endl;
    std::cin >>newPassword;

    std::cout << "What is the email assocaited with this Account?" << std::endl;
    std::cin >> newEmail;

    Account newAccount = new Account(newSource,newUsername,newPassword,newEmail);

    return Account;

}