#include"Users.h"
#include"Librarian.h"
#include"Library.h"
#include"Client.h"
using namespace std;


int main()
{
    ReallyLongInt x;
    ReallyLongInt y;
    string s;
    cin>>s;
    x=s;
    cout<<x*x;
    system("PAUSE");
    srand(time(NULL));
    Library library;
    Users* user;
    user = library.login();//login
    library.readArchives("archive");
    library.saveArchives("archive");
    user->viewOptions();//prompts the user for options
    return 0;
}
