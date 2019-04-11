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
    user = library.login();
    library.readArchives("archive");
    library.saveArchives("archive");
    user->viewOptions();
    return 0;
}
