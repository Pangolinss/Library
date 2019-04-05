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

Users::~Users()
{
    //dtor
}
