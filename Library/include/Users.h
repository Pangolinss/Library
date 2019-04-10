#ifndef USERS_H
#define USERS_H
#include<fstream>
#include<iostream>
#include<string>
#include<cstring>
#include<conio.h>
#include<windows.h>
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
        virtual void viewArchives(){return;}
        virtual void makeUser(std::string, std::string){return;}
        virtual void deleteUser(){return;}
        virtual void viewOptions(){return;}

        virtual void borrowBook(){return;}
        int menu(std::string[], int);

    private:
        std::string password;
        std::string username;

};
#endif // USERS_H
