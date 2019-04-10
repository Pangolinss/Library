#include "Client.h"

Client::Client()
{
    //ctor
}

Client::Client(std::string u, std::string p, Library* _library)
{
    setUsername(u);
    setPassword(p);
    library = _library;
}

void Client::borrowBook()
{
    Book book;
    std::ofstream fileOut;
    int val;

    val = menu(library->getBookList(), library->getNumBooks()+1);
    if (val == library->getNumBooks())
    {
        return;
    }
    else
    {
        fileOut.open("data\\Archives\\BorrowedBooks\\"+getUsername()+".DONTOPEN");
        book = library->lendBook(val);
        fileOut<<book.getTitle();
        fileOut<<book.getAuthor();
        fileOut<<book.getNumPages();
        fileOut<<book.getAvailability();
        fileOut.close();
    }
    library->saveArchives("archives");
}

void Client::viewOptions()
{
    std::string options_list[] = {"View Books", "Borrow Book", "Return Book", "Logout"};
    std::string t, a, n;
    int _menu;;
    bool leave = false;
    while (!leave)
    {
        _menu = menu(options_list, 4);
        switch (_menu)
        {
            case 0:
                system("CLS");
                library->outputArchives();
                system("PAUSE");
                break;
            case 1:
                borrowBook();
                break;
            case 2:
                break;
            case 3:
                leave = true;
                break;
            default:
                break;
        }
    }
}

Client::~Client()
{
    //dtor
}
