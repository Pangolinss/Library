#include "Library.h"

Library::Library()
{
    //ctor
}

Users* Library::login()
{
    std::ofstream fileOut;
    std::ifstream fileIn;
    std::string _username;
    std::string _password;
    std::string buffer;
    fileOut.open("data\\Users\\user.DONTOPEN", std::ios::app);//creates file
    fileOut.close();
    while (true)
    {
        fileIn.open("data\\Users\\user.DONTOPEN");
        std::cout<<"Username: ";
        std::cin>>_username;
        while (getline(fileIn, buffer))
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
                            Users* user = new Users(_password, _username);
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

void Library::saveBook(Book book, std::string str)
{
    std::ofstream fileOut;
    std::ifstream fileIn;
    fileIn.open("data\\Archives\\"+str+".DONTOPEN");
    if (!fileIn.is_open())
    {
        fileIn.close();
        fileOut.open("data\\Archives\\"+str+".DONTOPEN", std::ios::app);//creates file
    }
    else
    {
       fileIn.close();
       fileOut.open("data\\Archives\\"+str+".DONTOPEN", std::ios::app);//creates file
       fileOut<<"\n";
    }
    fileOut<<book.getTitle()<<"\n";
    fileOut<<book.getAuthor()<<"\n";
    fileOut<<book.getNumPages()<<"\n";
    fileOut<<book.getAvailability();
    fileOut.close();
}

void Library::deleteBook(Book book, std::string _str)
{
    Book buffer;
    std::string str;
    std::ifstream fileIn;
    std::ofstream tempFile;
    std::string newstr = "data\\Archives\\"+_str+".DONTOPEN";
    char* cstr = new char[newstr.size()+1];
    char* cstr1;
    std::strncpy(cstr, newstr.c_str(), newstr.size());
    fileIn.open("data\\Archives\\"+_str+".DONTOPEN", std::ios::in);
    bool endFile = false;
    //tempFile.open("data\\Archives\\temp.DONTOPEN");
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
        if (buffer!= book)
        {
            saveBook(buffer, "temp");
        }
    }
    fileIn.close();
    std::remove(cstr);
    newstr = "data\\Archives\\temp.DONTOPEN";
    cstr1 = new char[newstr.size()+1];
    std::strncpy(cstr1, newstr.c_str(), newstr.size());
    std::rename(cstr1, cstr);

}

void Library::readArchives(std::string str)
{
    std::ifstream fileIn;
    fileIn.open("data\\Archives\\"+str+".DONTOPEN");
    std::string line;
    if (fileIn.is_open())
    {
        int i = 0;
        while (fileIn.is_open())
        {
            getline(fileIn, line);
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
    }
    fileIn.close();
}

Library::~Library()
{
    //dtor
}
