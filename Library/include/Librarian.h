#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include <Users.h>
#include<windows.h>

class Library;
class Librarian : public Users
{
    public:
        Librarian();
        Librarian(std::string, std::string, Library* _library);
        virtual ~Librarian();

        void addBook(Book);
        void removeBook(Book);

    private:
        Library* library;

};

#endif // LIBRARIAN_H
