#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include "Users.h"
#include"Library.h"

class Library;
class Librarian : public Users//inherits stuff from users
{
    public:
        Librarian();
        Librarian(std::string, std::string, Library* _library);
        virtual ~Librarian();

        void addBook(Book);
        void removeBook(Book);
        void editBook();
        void viewArchives();
        void makeUser(std::string, std::string);
        void deleteUser(std::string);
        void viewOptions();

    private:
        Library* library;
        void addBook(std::string, std::string, std::string);
        void removeBook();
};

#endif // LIBRARIAN_H
