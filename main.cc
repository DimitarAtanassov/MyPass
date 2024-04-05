#include <iostream>
#include <string>
#include <limits>
#include "PasswordManger.hh"
#include "Account.hh"
#include "Security.hh"
#include <fstream>
#include <cryptopp/cryptlib.h>

std::string menu();

int main (int argc, char* argv[])
{
    Security security;
    std::string inputFilename = "encrypted_passwords.txt"; // OPTIONAL: Update to your preference
    std::string decryptedFilename = "passwords.txt"; // OPTIONAL: Update to your preference
    std::string password = "userpassword";  //Change this to what ever you want your file to be encrypted with
    unsigned int keySize = 16; // key size for AES-128
    CryptoPP::SecByteBlock key = security.DeriveKeyFromPassword(password, nullptr, 0, keySize);

    // Check if the file exists and if it is encrypted
    std::ifstream inputFile(inputFilename, std::ios::binary);
    if (!inputFile) {
        std::cerr << "\033[;35mEncrypted password file does not exist or is empty. Skipping decryption.\033[0m" << std::endl;
        // If file does not exist it will be created when you first add a new password
        // File is also encrypted when the program is closed
    }
    else
    {
        security.DecryptPasswordFile(inputFilename, decryptedFilename, key);
    }

    std::string appCommand;
    std::cout << "\033[;34m============================\033[0m" << std::endl;
    std::cout << "\033[;34m         MyPass\033[0m" << std::endl;
    std::cout << "\033[;34m============================\033[0m\n" << std::endl;
    appCommand = menu();
    PasswordManager manager;
    if(appCommand == "Add")
    {
        Account* newAccount = manager.addPassword();
        manager.writeToFile(newAccount->getSource(), newAccount->getUsername(), newAccount->getPassword(), newAccount->getEmail());
        std::cout << "\033[1;32mPassword saved!\033[0m" << std::endl;
    }

    else if (appCommand == "Get")
    {
        std::string passwordSrc;
        std::cout << "\n\033[1;34m-------------------------------------\033[0m" << std::endl;
        std::cout << "\033[1;36mWhat Password would you like to get? \033[0m";
        std::cin >> passwordSrc;
        std::cout << "\033[1;34m-------------------------------------\033[0m" << std::endl;
        Account* newAccount = manager.getPassword(passwordSrc);
        if(newAccount->getUsername() == "")
        {
            std::cout << "\033[1;31m Password for: " << passwordSrc << " not found\033[0m" << std::endl;
        }
        else
        {
            std::cout << "\n\033[1;36mAccount username: \033[0m" << newAccount->getUsername() << std::endl;
            std::cout << "\033[1;36mAccount password: \033[0m" << newAccount->getPassword() << std::endl;
            std::cout << "\033[1;36mAccount email: \033[0m" << newAccount->getEmail() << std::endl;
            std::cout << "" << std::endl;
        }
    }

    else if (appCommand == "Delete")
    {
        std::string passwordSrc;
        std::cout << "\n\033[1;31m-------------------------------------\033[0m" << std::endl;
        std::cout << "\033[1;31mWhat Password would you like to delete? \033[0m";
        std::cin >> passwordSrc;
        std::cout << "\033[1;31m-------------------------------------\033[0m\n" << std::endl;
        manager.deletePassword(passwordSrc);
    }

    else if (appCommand == "Update")
    {
        std::string passwordSrc;
        std::string newPassword;
        std::cout << "\n\033[1;33m---------------------------------------\033[0m" << std::endl;
        std::cout << "\033[1;33mWhat Password would you like to update? \033[0m";
        std::cin >> passwordSrc;
        std::cout << "\033[1;33m---------------------------------------\033[0m\n" << std::endl;
        std::cout << "\033[1;33mWhat is the new password? \033[0m";
        std::cin >> newPassword;
        std::cout << "" << std::endl;
        manager.updatePassword(passwordSrc,newPassword);
    }

    security.EncryptPasswordFile(decryptedFilename, inputFilename, key);
    std::remove(decryptedFilename.c_str());
    return 0;

}

std::string menu()
{
    bool validChoice = false;
    int userChoice;
    std::string appCommand;

    while(!validChoice)
    {
        std::cout << "\033[1;34mWhat would you like to do?\033[0m" << std::endl;
        std::cout << "\033[;36m 1.) Get Password \033[0m" << std::endl;
        std::cout <<"\033[;32m 2.) Add Password \033[0m" << std::endl;
        std::cout <<"\033[;33m 3.) Update Password \033[0m" << std::endl;
        std::cout <<"\033[;31m 4.) Delete Password \033[0m" << std::endl;
        std::cout << "" << std::endl;
        std::cout <<"Enter the corresponding number: ";
        std::cin >> userChoice;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "\033[;31m Invalid input. Please enter a number 1-4\033[0m" << std::endl;
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

    return appCommand;
}