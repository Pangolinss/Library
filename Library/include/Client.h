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
        void viewOptions();
        virtual ~Client();
    private:
        Library* library;
};

#endif // CLIENT_H
