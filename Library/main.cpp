#include"Users.h"
#include"Librarian.h"
#include"Library.h"
#include"Client.h"
using namespace std;


int main()
{
    srand(time(NULL));
    Library library;
    Users* user;
    Book book1("a","a",1,1);
    Book book2("b", "b", 1, 1);
    Book book3("c", "c", 1, 1);
    user = library.login();
    library.readArchives("archives");
    user->addBook(book1);
    user->addBook(book2);
    user->addBook(book3);
    library.saveArchives("archives");
    user->viewOptions();
    return 0;
}
