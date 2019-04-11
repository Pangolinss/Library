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
        if (library->getArchiveAvail(val) == true)
        {
            book = library->lendBook(val);
            fileOut.open("data\\Archives\\BorrowedBooks\\"+getUsername()+".DONTOPEN");
            fileOut<<book.getTitle();
            fileOut<<book.getAuthor();
            fileOut<<book.getNumPages();
            fileOut<<book.getAvailability();
            fileOut.close();
        }
        else
        {
            std::cout<<"Book taken"<<std::endl;
        }
    }
    library->saveArchives("archive");
}

void Client::returnBook()
{
    std::ifstream fileIn;
    std::ofstream fileOut;
    std::string buf;
    std::string arr[100];
    int i = 0;
    int val;

    fileIn.open("data\\Users\\BorrowedBooks\\"+getUsername()+".DONTOPEN");
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
    if (val == i-1)
    {
        return;
    }
    else
    {
        Book book;
        fileOut.open("data\\Users\\BorrowedBooks\\temp");
        fileIn.open("data\\Users\\BorrowedBooks\\"+getUsername()+".DONTOPEN");
        library->returnBook(val);
        char* cstr1;
        char* cstr2;
        std::string s1, s2;

        while(!fileIn.eof())
        {
            getline(fileIn, buf);
            book.setAuthor(buf);
            getline(fileIn, buf);
            book.setAuthor(buf);
            getline(fileIn, buf);
            book.setNumPages(std::stoi(buf));
            getline(fileIn, buf);
            book.setAvailability(std::stoi(buf));
            if (book != library->getBook(val))
            {
                library->saveBook(book, "data\\Users\\BorrowedBooks\\temp");
            }
        }
        s1 = "data\\Users\\BorrowedBooks\\temp";
        s2 = "data\\Users\\BorrowedBooks\\"+getUsername()+".DONTOPEN";
        cstr1 = new char[s1.size()+1];
        cstr2 = new char[s2.size()+1];
        std::strncpy(cstr1, s1.c_str(), s1.size());
        std::strncpy(cstr2, s2.c_str(), s2.size());
        remove(cstr2);
        rename(cstr1,cstr2);
    }

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
                library->saveArchives("archive");
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
