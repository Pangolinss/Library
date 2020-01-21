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

void Librarian::addBook(Book book)//Adds book if you have a book created
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

void Librarian::addBook(std::string t, std::string a, std::string n)//Adds a book if you don't have a book already created
{
    int _n;
    try//Makes sure you are adding a book with integer page nubmers, as you will probably cin a string
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

void Librarian::removeBook(Book book)//removes book from the array of books in the library by sending it a book
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

void Librarian::removeBook()//an alternative remove book that prompts the user to pick a book and remove it
{
    std::string* strarr = new std::string [library->first_empty_position+1];
    int val;
    for (int i = 0 ;i<library->first_empty_position+1; i++)
    {
        strarr[i] = library->getBookList()[i];
    }
    val = menu(strarr, library->first_empty_position+1);//menu to prompt user
    if (val == library->first_empty_position)
    {
        return;
    }
    else
    {
        removeBook(library->archive[val]);
        library->saveArchives("archive");
    }
    return;
}

void Librarian::editBook()//edits a book by asking the user what book to edit
{
    int val;
    std::string* arr = library->getBookList();
    val = menu(arr, library->first_empty_position+1);
    if (val == library->first_empty_position)
    {
        return;
    }
    else
    {
        if (library->archive[val].getAvailability())
        {
             std::string newarr[] = {"Title", "Author", "Page Num", "Back"};
             val = menu(newarr, 4);
             if (val == 3)
             {
                 return;
             }
             else
             {
                 std::string input;
                 std::cin>>input;
                 switch (val)
                 {
                    case 0:
                        library->archive[val].setTitle(input);
                        break;
                    case 1:
                        library->archive[val].setAuthor(input);
                        break;
                    case 2:
                        int n;
                        try
                        {
                            n = std::stoi(input);
                        }
                        catch(std::invalid_argument e)
                        {
                            std::cout<<"Invalid argument"<<std::endl;
                            return;
                        }
                        library->archive[val].setNumPages(n);
                        break;
                    default:
                        break;
                 }
             }
        }
        else
        {
            std::cout<<"Book not in library"<<std::endl;
        }
    }
}

void Librarian::viewArchives()
{
    library->outputArchives();
}

void Librarian::makeUser(std::string u, std::string p)//makes a user and checks to see if a user with the same properties already exists
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

void Librarian::deleteUser(std::string a)//decided against deleting users so it does nothing
{

}

void Librarian::viewOptions()//shows options for a librarian
{
    std::string options_list[] = {"View Books", "Add Book", "Remove Book", "Edit Book", "Make Users", "Logout"};
    std::string t, a, n;
    std::string u, p;
    int _menu;;
    bool leave = false;
    while (!leave)
    {
        _menu = menu(options_list, 6);
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
                library->saveArchives("archive");//saves the files so it should be called whenever editing something
                break;
            case 2:
                removeBook();
                break;
            case 3:
                editBook();
                library->saveArchives("archive");
                break;
            case 4:
                std::cout<<"Username: "<<std::endl; std::cin>>u;
                std::cout<<"Password: "<<std::endl; std::cin>>p;
                makeUser(u, p);
                break;
            case 5:
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
