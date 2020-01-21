#ifndef LIBRARY_H
#define LIBRARY_H
#define MAX_BOOKS 100
#define PRIVATE_KEY 18514//a prime number for encryption
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
        bool getArchiveAvail(int);
        Book getBook(int);

        Book lendBook(int);
        void returnBook(int);
        void outputArchives();
        void readArchives(std::string);
        void saveArchives(std::string);

        void saveBook(Book, std::string);
        void deleteBook(Book, std::string);

        void encryptFile(std::string);//originally used for encryption but cant perform calculations with numbers large enough to actually encrypt stuff

    private:
        Book archive[MAX_BOOKS];
        int first_empty_position;
        friend class Librarian;
        void decryptFile(std::string);//currently not implemented
};

#endif // LIBRARY_H
