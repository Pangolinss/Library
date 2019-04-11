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
    for (int i = 0; i<library->first_empty_position; i++)
    {
        if (book <= library->archive[i])
        {
            std::cout<<"\""<<book.getAuthor()<<"\""<<" already exists"<<std::endl;
            return;
        }
    }
    library->archive[library->first_empty_position++] = book;
}

void Librarian::addBook(std::string t, std::string a, std::string n)
{
    int _n;
    try
    {
        _n = std::stoi(n);
    }
    catch(std::invalid_argument e)
    {
        std::cout<<"Invalid argument"<<std::endl;
        return;
    }
    Book book(t, a, _n, false);
    addBook(book);
}

void Librarian::removeBook(Book book)
{
    for (int i = 0; i<library->first_empty_position; i++)
    {
        if (library->archive[i] == book)
        {
            for (int j = i+1; j<library->first_empty_position; j++)
            {
                library->archive[j-1] = library->archive[j];
            }
            library->first_empty_position--;
            return;
        }
        else if(library->archive[i] <= book && library->archive[i].getAvailability() == false)
        {
            std::cout<<"Cannot remove book that is currently being borrowed"<<std::endl;
        }
    }
    std::cout<<"\""<<book.getTitle()<<"\""<<" does not exists"<<std::endl;
}

void Librarian::removeBook()
{
    std::string* strarr = new std::string [library->first_empty_position+1];
    int val;
    for (int i = 0 ;i<library->first_empty_position+1; i++)
    {
        strarr[i] = library->getBookList()[i];
    }
    val = menu(strarr, library->first_empty_position+1);
    if (val == library->first_empty_position)
    {
        return;
    }
    else
    {
        removeBook(library->archive[val]);
        library->saveArchives("archives");
    }
    return;
}

void Librarian::viewArchives()
{
    library->outputArchives();
}

void Librarian::makeUser(std::string u, std::string p)
{
    std::ofstream fileOut;
    std::ifstream fileIn;
    std::string str, _u;
    fileIn.open("data\\Users\\user.DONTOPEN");
    while (getline(fileIn, str))
    {
        if (str == "~")
        {
            getline(fileIn, _u);
            if (_u == u)
            {
                std::cout<<"Username already exists"<<std::endl;
                return;
            }
        }
    }
    fileOut.open("data\\Users\\user.DONTOPEN", std::ios::app);
    fileOut<<"\n"<<"~"<<"\n"<<u<<"\n";
    fileOut<<p;
}

void Librarian::deleteUser(std::string a)
{

}

void Librarian::viewOptions()
{
    std::string options_list[] = {"View Books", "Add Book", "Remove Book", "Edit Book", "View Users", "Make Users", "Logout"};
    std::string t, a, n;
    int _menu;;
    bool leave = false;
    while (!leave)
    {
        _menu = menu(options_list, 7);
        switch (_menu)
        {
            case 0:
                system("CLS");
                viewArchives();
                system("PAUSE");
                break;
            case 1:
                std::cin>>t;
                std::cin>>a;
                std::cin>>n;
                addBook(t, a, n);
                library->saveArchives("archive");
                break;
            case 2:
                removeBook();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                library->saveArchives("archive");
                leave = true;
                break;
            default:
                break;
        }
    }
}

Librarian::~Librarian()
{
    //dtor
}
