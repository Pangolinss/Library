#ifndef LIBRARY_H
#define LIBRARY_H
#define MAX_BOOKS 100
#define PRIVATE_KEY 12227156
#include<ctime>
#include<cstdlib>
#include<cmath>
#include"ReallyLongInt.h"
#include"Librarian.h"
#include"Client.h"

class Librarian;
class Users;
class Library
{
    public:
        Library();
        virtual ~Library();

        int getNumBooks();

        Users* login();

        std::string* getBookList();
        Book lendBook(int);
        void outputArchives();
        void readArchives(std::string);
        void saveArchives(std::string);

        void encryptFile(std::string);

    private:
        Book archive[MAX_BOOKS];
        int first_empty_position;
        friend class Librarian;
        void saveBook(Book, std::string);
        void deleteBook(Book, std::string);
        void decryptFile(std::string);
};

#endif // LIBRARY_H
