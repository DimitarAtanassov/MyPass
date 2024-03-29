#include <iostream>
#include <string>
#include <limits>
#include "PasswordManger.hh"
#include "Account.hh"
#include "Security.hh"
#include <fstream>
#include <cryptopp/cryptlib.h> 
int main (int argc, char* argv[])
{
    Security security;
    std::string inputFilename = "encrypted_passwords.txt";
    std::string decryptedFilename = "passwords.txt";
    std::string password = "userpassword";
    unsigned int keySize = 16; // Example key size for AES-128
    CryptoPP::SecByteBlock key = security.DeriveKeyFromPassword(password, nullptr, 0, keySize);

    // Check if the file exists and if it is encrypted
    std::ifstream inputFile(inputFilename, std::ios::binary);
    if (!inputFile) {
        std::cerr << "Encrypted password file does not exist or is empty. Skipping decryption." << std::endl;
        // You may choose to create an empty file or handle this scenario differently
    }
    else
    {
        security.DecryptPasswordFile(inputFilename, decryptedFilename, key);
    }

    bool validChoice = false;
    int userChoice;
    std::string appCommand;
    std::cout << "============================" << std::endl;
    std::cout << "   MyPass     " << std::endl;
    std::cout << "============================\n" << std::endl;

    while(!validChoice)
    {   
        std::cout << "What would you like to do?" << std::endl;
        std::cout << " 1.) Get Password " << std::endl;
        std::cout <<" 2.) Add Password " << std::endl;
        std::cout <<" 3.) Update Password " << std::endl;
        std::cout <<" 4.) Delete Password " << std::endl;
        std::cout << "" << std::endl;
        std::cout <<" Enter the corresponding number: ";
        std::cin >> userChoice;

        // Invalid User Input
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number 1-4" << std::endl;
        }

        else
        {
            switch(userChoice)
            {
                case 1:
                    appCommand = "Get";
                    validChoice = true;
                    break;
                
                case 2:
                    appCommand = "Add";
                    validChoice = true;
                    break;

                case 3:
                    appCommand = "Update";
                    validChoice = true;
                    break;
                
                case 4:
                    appCommand = "Delete";
                    validChoice = true;
                    break;
            }
        }
    }
    PasswordManager manager;
    if(appCommand == "Add")
    {
        Account* newAccount = manager.addPassword();
        manager.writeToFile(newAccount->getSource(), newAccount->getUsername(), newAccount->getPassword(), newAccount->getEmail());
    }

    else if (appCommand == "Get")
    {
        std::string passwordSrc;
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "What Password would you like to get? ";
        std::cin >> passwordSrc;
        std::cout << "-------------------------------------" << std::endl;
        Account* newAccount = manager.getPassword(passwordSrc);
        std::cout << "Account username: " << newAccount->getUsername() << std::endl;
        std::cout << "Account password: " << newAccount->getPassword() << std::endl;
        std::cout << "Account email: " << newAccount->getEmail() << std::endl;
    }

    else if (appCommand == "Delete")
    {
        std::string passwordSrc;
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "What Password would you like to delete? ";
        std::cin >> passwordSrc;
        std::cout << "-------------------------------------" << std::endl;
        manager.deletePassword(passwordSrc);
    }

    else if (appCommand == "Update")
    {
        std::string passwordSrc;
        std::string newPassword;
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "What Password would you like to update? ";
        std::cin >> passwordSrc;
        std::cout << "What is the new password" << std::endl;
        std::cin >> newPassword;
        std::cout << "-------------------------------------" << std::endl;
        manager.updatePassword(passwordSrc,newPassword);
    }

    security.EncryptPasswordFile(decryptedFilename, inputFilename, key);
    std::remove(decryptedFilename.c_str());
    return 0;

}