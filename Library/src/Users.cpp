#include "Users.h"

Users::Users()
{
    //ctor
}

Users::Users(std::string p, std::string u)
{
    password = p;
    username = u;
}

std::string Users::getPassword()
{
    return password;
}
std::string Users::getUsername()
{
    return username;
}

void Users::setPassword(std::string _pass)
{
    password = _pass;
}
void Users::setUsername(std::string _user)
{
   username = _user;
}

int Users::menu(std::string options[], int arr_size)//A menu function
{
    std::string _menu[3][arr_size];
    int cursor = 0;
    bool chosen = false;
    char keypress;
    for (int j = 0; j<arr_size; j++)
    {
        _menu[0][j] = "";
        _menu[1][j] = options[j];
        _menu[2][j] = "";
    }
    while (!chosen)
    {
        for (int i = 0; i<arr_size; i++)
        {
            _menu[0][i] = " ";
            _menu[2][i] = " ";
        }
        _menu[0][cursor] = ">";
        _menu[2][cursor] = "<";
        for (int i = 0; i<arr_size; i++)
        {
            std::cout<<_menu[0][i];
            std::cout<<_menu[1][i];
            std::cout<<_menu[2][i];
            std::cout<<std::endl;
        }
        keypress = _getch();
        switch (keypress)
        {
            case 'w':
                (cursor == 0) ? (cursor = arr_size-1) : (--cursor);
                break;
            case 's':
                (cursor == arr_size-1) ? (cursor = 0) : (++cursor);
                break;
            case '\r':
                chosen = true;
                break;
            default:
                break;
        }
        system("CLS");
    }

    return cursor;
}

Users::~Users()
{
    //dtor
}
