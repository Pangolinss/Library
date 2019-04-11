#include "Book.h"

Book::Book()
{
    //ctor
    title = "";
    author = "";
    num_pages = 0;
    available = true;
}

Book::Book(std::string _title, std::string _author, int _num, bool _available)
{
    title = _title;
    author = _author;
    num_pages = _num;
    available = _available;
}

Book::~Book()
{
    //dtor
}

std::string Book::getTitle()
{
    return title;
}

std::string Book::getAuthor()
{
    return author;
}

int Book::getNumPages()
{
    return num_pages;
}

bool Book::getAvailability()
{
    return available;
}

void Book::setTitle(std::string _title)
{
    title = _title;
}
void Book::setAuthor(std::string _author)
{
    author = _author;
}
void Book::setNumPages(int _num_pages)
{
    num_pages = _num_pages;
}
void Book::setAvailability(bool _avail)
{
    available = _avail;
}

void Book::printBook()
{
    std::cout<<"Title: "<<title<<std::endl;
    std::cout<<"Author: "<<author<<std::endl;
    std::cout<<"Number Pages: "<<num_pages<<std::endl;
    std::cout<<"Available: "<<((available)? ("In Library") : ("Taken"))<<std::endl;
}

void Book::operator=(Book book)
{
    author = book.getAuthor();
    title = book.getTitle();
    num_pages = book.getNumPages();
    available = book.getAvailability();
}

bool Book::operator==(Book book)
{
    if (author == book.getAuthor() && title == book.getTitle() && num_pages == book.getNumPages() && available == book.getAvailability())
    {
        return true;
    }
    return false;
}

bool Book::operator<=(Book book)
{
    if (author == book.getAuthor() && title == book.getTitle() && num_pages == book.getNumPages())
    {
        return true;
    }
    return false;
}

bool Book::operator!=(Book book)
{
    if (!(author == book.getAuthor() && title == book.getTitle() && num_pages == book.getNumPages() && available == book.getAvailability()))
    {
        return true;
    }
    return false;
}
