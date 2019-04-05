#include "Librarian.h"

Librarian::Librarian()
{
    //ctor
}

Librarian::Librarian(std::string p, std::string u, Library* _library)
{
    setPassword(p);
    setUsername(u);
    library = _library;
}

void Librarian::addBook(Book book)
{
    library->archive[library->first_empty_position] = book;
}

void Librarian::removeBook(Book book)
{
    library->first_empty_position--;
}

Librarian::~Librarian()
{
    //dtor
}
