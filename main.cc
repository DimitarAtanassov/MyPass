#include <iostream>
#include <string>
#include <limits>

int main (int argc, char* argv[])
{
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

    if (appCommand == "Add")
    {
        
    }

    return 0;

}