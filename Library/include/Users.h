#ifndef USERS_H
#define USERS_H
#include<fstream>
#include<iostream>
#include<string>
#include<cstring>
#include"Book.h"

class Users
{
    public:
        Users();
        Users(std::string, std::string);
        virtual ~Users();
        std::string getPassword();
        std::string getUsername();

        void setPassword(std::string);
        void setUsername(std::string);

        virtual void addBook(Book book){std::cout<<username<<" is not in the sudoers file"<<std::endl<<"This incident will be reported"<<std::endl;return;}
        virtual void removeBook(Book book){return;}

    private:
        std::string password;
        std::string username;

};

#endif // USERS_H
