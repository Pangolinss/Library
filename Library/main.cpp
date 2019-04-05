#include"Library.h"
#include"Librarian.h"
#include"Users.h"

int main()
{
    Library library;
    Users* user;
    Book book1("a","a",1,0);
    Book book2("b", "b", 1, 0);
    Book book3("c", "c", 1, 0);
    user = library.login();
    library.saveBook(book1, "archive");
    library.saveBook(book2, "archive");
    library.saveBook(book3, "archive");
    library.deleteBook(book1, "archive");
    return 0;
}
