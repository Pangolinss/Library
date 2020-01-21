#ifndef CLIENT_H
#define CLIENT_H

#include <Users.h>
#include"Library.h"

class Library;
class Client : public Users
{
    public:
        Client();
        Client(std::string, std::string, Library*);
        void borrowBook();
        void returnBook();
        void viewOptions();
        virtual ~Client();
    private:
        Library* library;
        Book myBooks[100];
};

#endif // CLIENT_H
