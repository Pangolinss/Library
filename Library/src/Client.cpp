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

void Client::borrowBook()//borrows a book by asking the library to lend a book, then saves the book to a file
{
    Book book;
    int val;

    val = menu(library->getBookList(), library->getNumBooks()+1);
    if (val == library->getNumBooks())
    {
        return;
    }
    else
    {
        if (library->getArchiveAvail(val) == true)
        {
            book = library->lendBook(val);
            library->saveBook(book, "data\\Users\\BorrowedBooks\\"+getUsername()+".DONTOPEN");
        }
        else
        {
            std::cout<<"Book taken"<<std::endl;
        }
    }
    library->saveArchives("archive");
}

void Client::returnBook()//returns book by going to an array of borrowed books and then giving them back to the library
{//delete book function is called to remove the book from the saved book file
    std::ifstream fileIn;
    std::ofstream fileOut;
    std::string buf;
    std::string arr[100];
    int i = 0;
    int val;

    fileIn.open("data\\Users\\BorrowedBooks\\"+getUsername()+".DONTOPEN");
    if (!fileIn.is_open())
    {
        std::cout<<"No borrowed books"<<std::endl;
        return;
    }
    while(!fileIn.eof())
    {
        getline(fileIn, buf);
        arr[i] = buf;
        getline(fileIn, buf);
        getline(fileIn, buf);
        getline(fileIn, buf);
        i++;
    }
    fileIn.close();
    arr[i++] = "Back";
    val = menu(arr, i);
    fileIn.close();
    if (val == i-1)
    {
        return;
    }
    else
    {
        Book book = library->getBook(val);
        std::string s1, s2;
        library->returnBook(val);
        library->deleteBook(book, "data\\Users\\BorrowedBooks\\"+getUsername()+".DONTOPEN");
    }

}

void Client::viewOptions()//options for a client
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
                library->saveArchives("archive");
                break;
            case 2:
                returnBook();
                library->saveArchives("archive");
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
