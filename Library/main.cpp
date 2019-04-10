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
    std::string str = "3425452345234523453536563345634563456345624";
    ReallyLongInt x;
    x = str;
    str = "45555553634563456555";
    ReallyLongInt y;
    y = str;
    str = "23";
    ReallyLongInt z;
    z = str;
    cout<<x*y<<endl;
    /*
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
    */
    return 0;
}
