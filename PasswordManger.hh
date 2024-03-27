

#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H
#include <map>
#include <string>
#include "Account.hh"
class PasswordManager
{
    public:
            Account getPassword(const std::string&);
            PasswordManager();
    private:
        

}


#endif