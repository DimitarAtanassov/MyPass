#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
    public:

        std::string getSource();
        std::string getUsername();
        std::string getPassword();
        std::string getEmail();
        
        void setSource(const std::string& );
        void setUsername(const std::string& );
        void setPassword(const std::string& );
        void setEmail(const std::string& );
    private:
        std::string source;
        std::string username;
        std::string password;
        std::string email;

}


#endif