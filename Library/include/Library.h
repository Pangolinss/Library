#ifndef LIBRARY_H
#define LIBRARY_H
#define MAX_BOOKS 100

#include<fstream>
#include<iostream>
#include<string>
#include"Book.h"
#include"Users.h"
#include"Librarian.h"

class Library
{
    public:
        Library();
        virtual ~Library();
        Users* login();
        void saveBook(Book, std::string);
        void deleteBook(Book, std::string);
        void readArchives(std::string);





    private:
        Book archive[MAX_BOOKS];
        int first_empty_position;
        friend class Librarian;
};

#endif // LIBRARY_H
