#include "PasswordManger.hh"
#include "Account.hh"
#include <iostream>
#include <string>
#include <fstream>
PasswordManager::PasswordManager()
{

};

Account* PasswordManager::addPassword()
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
    
    Account* newAccount = new Account(newSource,newUsername,newPassword,newEmail);

    return newAccount;

}

void PasswordManager::writeToFile(const std::string& src, const std::string& username, const std::string& password, const std::string& email)
{
    std::ofstream myFile;
    myFile.open("C:/Users/dimit/OneDrive/Desktop/mypasswords.txt");
    myFile << "" << std::endl;
    myFile << src << std::endl;
    myFile << username << std::endl;
    myFile << password << std::endl;
    myFile << email << std::endl;
    myFile << "" << std::endl;
    myFile.close();
}