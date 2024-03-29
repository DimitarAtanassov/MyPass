#include "PasswordManger.hh"
#include "Account.hh"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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
    myFile.open("/home/dimitar/Documents/C++ Mypass/passwords.txt", std::ios::app);
    myFile << "" << std::endl;
    myFile << src << std::endl;
    myFile << username << std::endl;
    myFile << password << std::endl;
    myFile << email << std::endl;
    myFile << "" << std::endl;
    myFile.close();
}

Account* PasswordManager::getPassword(const std::string& src)
{
    std::ifstream myFile;
    std::string line;
    Account* foundAccount = nullptr; // Initialize foundAccount to nullptr
    std::string accountSrc;
    std::string accountUsername;
    std::string accountPassword;
    std::string accountEmail;
    bool inAccountSection = false;
    
    myFile.open("/home/dimitar/Documents/C++ Mypass/passwords.txt");
    
    if (myFile.is_open())
    {
        while (getline(myFile, line))
        {
            if (inAccountSection)
            {
                if (line.empty()) // End of account section
                {
                    foundAccount = new Account(accountSrc, accountUsername, accountPassword, accountEmail);
                    break;
                }
                
                // Store username, password, and email in corresponding variables
                if (accountUsername.empty())
                    accountUsername = line;
                else if (accountPassword.empty())
                    accountPassword = line;
                else if (accountEmail.empty())
                    accountEmail = line;
            }
            else if (line == src)
            {
                inAccountSection = true;
                accountSrc = line;
            }
        }
    }
    
    myFile.close();
    
    return foundAccount; // Return the found account, nullptr if not found
}

void PasswordManager::deletePassword(const std::string& srcToDelete)
{
    std::ifstream inputFile("/home/dimitar/Documents/C++ Mypass/passwords.txt");
    std::ofstream outputFile("/home/dimitar/Documents/C++ Mypass/temp.txt");

    std::string line;
    std::string currentSrc;

    bool found = false;
    bool inAccountSection = false;

    while (getline(inputFile, line))
    {
        if (inAccountSection)
        {
            if (line.empty()) // End of account section
            {
                inAccountSection = false; // Exiting the account section
                if (currentSrc != srcToDelete)
                {
                    // Write back the account if it's not the one to delete
                    outputFile << currentSrc << std::endl;
                    outputFile << line << std::endl;
                }
                else
                {
                    found = true; // Marking the account as found
                }
            }
            else if (currentSrc != srcToDelete)
            {
                // Write back all lines except the ones belonging to the account to delete
                outputFile << line << std::endl;
            }
        }
        else if (line == srcToDelete)
        {
            inAccountSection = true; // Entering the account section
            currentSrc = line;
        }
        else
        {
            // Write back lines that are not part of any account section
            outputFile << line << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();

    // Replace the original file with the temporary file
    std::remove("/home/dimitar/Documents/C++ Mypass/passwords.txt");
    std::rename("/home/dimitar/Documents/C++ Mypass/temp.txt", "/home/dimitar/Documents/C++ Mypass/passwords.txt");

    if (found)
    {
        std::cout << "Password with source '" << srcToDelete << "' has been deleted." << std::endl;
    }
    else
    {
        std::cout << "Password with source '" << srcToDelete << "' not found." << std::endl;
    }
}

void PasswordManager::updatePassword(const std::string& passwordSrc, const std::string& newPassword)
{

    std::ifstream inputFile("/home/dimitar/Documents/C++ Mypass/passwords.txt");
    std::ofstream outputFile("/home/dimitar/Documents/C++ Mypass/temp.txt");

    std::string line;
    std::string currentSrc;

    bool found = false;
    bool inAccountSection = false;
    while (getline(inputFile, line))
    {
        if (inAccountSection)
        {
            if(line.empty())
            {
                inAccountSection = false;
                outputFile << line << std::endl;     
            }
            else
            {
                outputFile << line << std::endl;
                getline(inputFile,line);
                outputFile << newPassword << std::endl;
                getline(inputFile,line);
                outputFile << line << std::endl;
            }


            
           
        }
        else if (line == passwordSrc)
        {
            inAccountSection = true;
            outputFile << line << std::endl;
            currentSrc = line;
        }
        else
        {
            outputFile << line << std::endl;
        }
    }
    inputFile.close();
    outputFile.close();
    std::remove("/home/dimitar/Documents/C++ Mypass/passwords.txt");
    std::rename("/home/dimitar/Documents/C++ Mypass/temp.txt", "/home/dimitar/Documents/C++ Mypass/passwords.txt");
}
