#ifndef BOOK_H
#define BOOK_H

#include<iostream>

class Book
{
    public:
        Book();
        Book(std::string, std::string, int, bool);
        virtual ~Book();
        std::string getTitle();
        std::string getAuthor();
        int getNumPages();
        bool getAvailability();

        void setTitle(std::string);
        void setAuthor(std::string);
        void setNumPages(int);
        void setAvailability(bool);

        void printBook();

        void operator=(Book);
        bool operator==(Book);
        bool operator<=(Book); //compares everything but availability
        bool operator!=(Book);


    private:
        std::string title;
        std::string author;
        int num_pages;
        bool available;
};

#endif // BOOK_H
