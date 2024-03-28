

#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H
#include <map>
#include <string>
#include "Account.hh"
class PasswordManager
{
    public:
            Account* addPassword();
            PasswordManager();
            void writeToFile(const std::string&, const std::string&, const std::string&, const std::string&);
            Account* getPassword(const std::string&);
    private:
        

};


#endif