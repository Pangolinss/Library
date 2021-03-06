#include "Library.h"

Library::Library()
{
    //ctor
    first_empty_position = 0;
}
//Get and set functions

int Library::getNumBooks()
{
    return first_empty_position;
}
std::string* Library::getBookList()
{
    std::string* titles;
    titles = new std::string[first_empty_position+1];
    for (int i = 0 ;i<first_empty_position; i++)
    {
        titles[i] = archive[i].getTitle();
    }
    titles[first_empty_position] = "Back";
    return titles;
}

Book Library::getBook(int i)
{
    return archive[i];
}

bool Library::getArchiveAvail(int i)
{
    return archive[i].getAvailability();
}


//
//Functions to lend and return books


Book Library::lendBook(int i)
{
    if (archive[i].getAvailability() == true)
    {
        archive[i].setAvailability(false);
    }
    return archive[i];
}

void Library::returnBook(int i)
{
    archive[i].setAvailability(true);
}

Users* Library::login()//Login function, will return a pointer to a Librarian if you log in as a librarian, otherwise returns a Client
{
    std::ofstream fileOut;
    std::ifstream fileIn;
    std::string _username;
    std::string _password;
    std::string buffer;
    fileIn.open("data\\Users\\user.DONTOPEN");
    if (!fileIn.is_open())
    {
        fileOut.open("data\\Users\\user.DONTOPEN", std::ios::app);//creates file
        fileOut<<"~"<<"\n"<<"Librarian"<<"\n"<<"admin";
        fileOut.close();
    }
    fileIn.close();
    while (true)
    {
        fileIn.open("data\\Users\\user.DONTOPEN");
        std::cout<<"Username: ";
        std::cin>>_username;
        while (getline(fileIn, buffer))//function checks if you have the correct login credentials
        {
            if (buffer == "~")
            {
                getline(fileIn, buffer);
                if (buffer == _username)
                {
                    std::cout<<std::endl;
                    std::cout<<"Password: ";
                    std::cin>>_password;
                    getline(fileIn, buffer);
                    if (_password == buffer)
                    {
                        if (_username == "Librarian")
                        {
                            Librarian* user = new Librarian(_password, _username, this);
                            fileIn.close();
                            return user;
                        }
                        else
                        {
                            Client* user = new Client(_password, _username, this);
                            fileIn.close();
                            return user;
                        }
                    }
                }
            }
        }
        fileIn.close();
        std::cout<<"Login Information incorrect"<<std::endl;
    }
    return nullptr;
}

void Library::saveBook(Book book, std::string str)//save a book to a file
{
    std::ofstream fileOut;
    std::ifstream fileIn;
    fileIn.open(str);
    if (!fileIn.is_open())
    {
        fileIn.close();
        fileOut.open(str, std::ios::app);//creates file
    }
    else
    {
       fileIn.close();
       fileOut.open(str, std::ios::app);//creates file
       fileOut<<"\n";
    }
    fileOut<<book.getTitle()<<"\n";
    fileOut<<book.getAuthor()<<"\n";
    fileOut<<book.getNumPages()<<"\n";
    fileOut<<book.getAvailability();
    fileOut.close();
}

void Library::deleteBook(Book book, std::string _str)//deletes a book, does this by creating another text file and copying all lines that you want, then deletes the old one
{
    Book buffer;
    std::string str;
    std::ifstream fileIn;
    std::ofstream tempFile;
    std::string s1, s2;
    fileIn.open(_str, std::ios::in);
    while (!fileIn.eof())
    {
        getline(fileIn, str);
        buffer.setTitle(str);

        getline(fileIn, str);
        buffer.setAuthor(str);

        getline(fileIn, str);
        buffer.setNumPages(std::stoi(str));

        getline(fileIn, str);
        buffer.setAvailability(std::stoi(str));
        if (!(buffer<= book))//goes through a file and copies all lines that you don't want deleted
        {
            saveBook(buffer, "temp");
        }
    }
    fileIn.close();
    s1 = "temp";
    s2 = _str;
    std::remove(s2.c_str());//removes the old file
    std::rename(s1.c_str(), s2.c_str());//renames the temp file

}

void Library::readArchives(std::string str)//reads the file and puts it into the actual book array
{
    std::ifstream fileIn;
    fileIn.open("data\\Archives\\"+str+".DONTOPEN");
    std::string line;
    if (fileIn.is_open())
    {
        int i = 0;
        while (!fileIn.eof())
        {
            getline(fileIn, line);
            if (line == "")
            {
                break;
            }
            archive[i].setTitle(line);
            getline(fileIn, line);
            archive[i].setAuthor(line);
            getline(fileIn, line);
            archive[i].setNumPages(std::stoi(line));
            getline(fileIn, line);
            archive[i].setAvailability(std::stoi(line));
            i++;
        }
        first_empty_position = i;
        fileIn.close();
    }
    else
    {
        fileIn.close();
        std::ofstream fileOut;
        fileOut.open("data\\Archives\\"+str+".DONTOPEN");
        fileOut.close();
    }
}

void Library::saveArchives(std::string str)//saves all the books to a file
{
    std::fstream fileIn;
    std::ofstream fileOut;
    std::string newstr = "data\\Archives\\"+str+".DONTOPEN";
    char* cstr;

    cstr = new char[newstr.size()+1];
    std::strncpy(cstr, newstr.c_str(), newstr.size());
    remove(cstr);

    fileOut.open("data\\Archives\\"+str+".DONTOPEN");
    fileOut.close();
    fileIn.open("data\\Archives\\"+str+".DONTOPEN");
    if (fileIn.is_open())
    {
        fileIn<<archive[0].getTitle()<<"\n";
        fileIn<<archive[0].getAuthor()<<"\n";
        fileIn<<archive[0].getNumPages()<<"\n";
        fileIn<<archive[0].getAvailability();
        for (int i = 1; i<first_empty_position; i++)
        {
            fileIn<<"\n";
            fileIn<<archive[i].getTitle()<<"\n";
            fileIn<<archive[i].getAuthor()<<"\n";
            fileIn<<archive[i].getNumPages()<<"\n";
            fileIn<<archive[i].getAvailability();
        }
    }
    else
    {
        std::cout<<"Failed to save archives, make sure to call openLibrary() first"<<std::endl;
    }
}

void Library::outputArchives()//just outputs stuff
{
    for (int i = 0; i<first_empty_position; i++)
    {
        archive[i].printBook();
    }
}

void Library::encryptFile(std::string name)//RSA encryption by generating two really large prime numbers. Each character is then encrypted and a the public key and the encyrpter is written to the file
{//Each time you call this function it generates one new prime number for encryption, and multiplies by the prime number that we have defined as PUBLIC_KEY
    unsigned long long p;
    bool found = false;
    unsigned long long public_key;
    unsigned long long m;
    unsigned long long encrypter;
    ReallyLongInt a, b, c;
    int k;

    std::ifstream fileIn;
    std::ofstream fileOut;
    std::string str, buf;

    p = rand()%100+100;
    p *= rand()%9+1;
    while (!found)
    {
        p += 2;
        found = true;
        for (unsigned long i = 3; i < sqrt(p)+1; i=i+2)
        {
            if (p%i == 0)
            {
                i = p;
                found = false;
            }
        }
    }
    public_key = PRIVATE_KEY*p;
    m = (PRIVATE_KEY-1)*(p-1);
    found = false;
    while (!found)
    {
        encrypter = rand()%100+100;
        encrypter *= rand()%9+1;
        if (gcd(encrypter,m) == 1)
        {
            found = true;
        }
        encrypter++;
    }

    fileIn.open(name);
    if (fileIn.is_open())
    {
        getline(fileIn, buf);
        str+= buf;
        while (getline(fileIn, buf))
        {
            str+="\n";
            str+=buf;
        }
    }
    fileIn.close();
    fileOut.open("temp");
    fileOut<<public_key<<"\n";
    fileOut<<encrypter<<"\n";
    for(char& it : str)
    {
        k = it;
        a = k;
        b = encrypter;
        c = m;
        fileOut<<modExp(a,b,c)<<"\n";//rsa encryption function
    }
}

Library::~Library()
{
    //dtor
}
