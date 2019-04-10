#include "ReallyLongInt.h"

ReallyLongInt::ReallyLongInt()
{
    //ctor
    for (int i = 0; i<MAX_LENGTH; i++)
    {
        value[i] = 0;
    }
}

void ReallyLongInt::operator=(ReallyLongInt x)
{
    for (int i = 0; i<MAX_LENGTH; i++)
    {
        value[i] = x.value[i];
    }
}

void ReallyLongInt::operator=(unsigned long long x)
{
    std::string str;
    str = std::to_string(x);
    int i = 0;
    for (auto it = str.crbegin(); it != str.crend(); ++it)
    {
        value[i] = *it-'0';
        i++;
    }
}

void ReallyLongInt::operator=(std::string str)
{
    int i = 0;

    for (auto it = str.crbegin(); it != str.crend(); ++it)
    {
        value[i] = *it-'0';
        i++;
    }
}

ReallyLongInt ReallyLongInt::operator+(ReallyLongInt x)
{
    ReallyLongInt sum;
    for (int i = 0; i<MAX_LENGTH; i++)
    {
        sum.value[i] += value[i]+x.value[i];
        sum.value[i+1] += sum.value[i]/BASE;
        sum.value[i] = sum.value[i]%BASE;
    }
    return sum;
}

ReallyLongInt ReallyLongInt::operator-(ReallyLongInt x)
{
    ReallyLongInt dif;
    for (int i = 0; i<MAX_LENGTH; i++)
    {
        dif.value[i] += value[i]-x.value[i];
        if (dif.value[i]<0)
        {
            dif.value[i+1]--;
            dif.value[i] +=10;
        }
    }
    return dif;
}

ReallyLongInt ReallyLongInt::operator-(unsigned long long x)
{
    ReallyLongInt a;
    a = x;
    return (*this - a);
}

void ReallyLongInt::operator++()
{
    int i = 0;
    value[i]++;
    bool done = false;
    while (!done)
    {
        done = true;
        if (value[i] >= BASE )
        {
            done = false;
            value[i+1] += value[i]/BASE;
            value[i] = value[i]%BASE;
        }
        i++;
    }
}

void ReallyLongInt::operator--()
{
    int i = 0;
    value[i]--;
    bool done = false;
    while (!done)
    {
        done = true;
        if (value[i] < 0 )
        {
            done = false;
            value[i+1]--;
            value[i] = 9;
        }
        i++;
    }
}

ReallyLongInt ReallyLongInt::operator*(ReallyLongInt x)
{
    int product[250][250];
    for (int i = 0; i<250; i++)
    {
        for (int j = 0; j<250; j++)
        {
            product[i][j] = 0;
        }
    }
    ReallyLongInt p;
    for (int i = 0; i<MAX_LENGTH; i++)
    {
        for (int k = 0; k<MAX_LENGTH; k++)
        {
            product[i][k+1] += (value[k]*x.value[i])/BASE;
            product[i][k] += (value[k]*x.value[i])%BASE;
        }
    }
    for (int i = 0; i<100; i++)
    {
        for (int k = 0; k<i+1; k++)
        {
            p.value[i] += product[k][i-k];
        }
        p.value[i+1] = p.value[i]/BASE;
        p.value[i] = p.value[i]%BASE;
    }
    return p;
}

ReallyLongInt ReallyLongInt::operator*(unsigned long long x)
{
    ReallyLongInt n;
    n = x;
    return (*this * n);
}

bool ReallyLongInt::operator<(ReallyLongInt x)
{
    for (int i = MAX_LENGTH-1; i>=0; i--)
    {
        if (value[i]<x.value[i])
        {
            return true;
        }
        else if(value[i]>x.value[i])
        {
            return false;
        }
    }
    return false;
}

bool ReallyLongInt::operator>(ReallyLongInt x)
{
    for (int i = MAX_LENGTH-1; i>=0; i--)
    {
        if (value[i]<x.value[i])
        {
            return false;
        }
        else if(value[i]>x.value[i])
        {
            return true;
        }
    }
    return false;
}

bool ReallyLongInt::operator==(ReallyLongInt x)
{
    for (int i = 0; i<MAX_LENGTH; i++)
    {
        if (value[i] != x.value[i])
        {
            return false;
        }
    }
    return true;
}

ReallyLongInt ReallyLongInt::operator/(ReallyLongInt x)
{
    ReallyLongInt zero;
    ReallyLongInt quotient;
    int qarr[100];
    ReallyLongInt buf;
    if (x == zero)
    {
        std::cout<<"Cannot divide by zero"<<std::endl;
        return zero;
    }
    else if (*this == zero || *this < x)
    {
        return zero;
    }
    else
    {
        quotient = 1;
        for (int i = 0; i<length()-x.length()-1; i++)
        {
            quotient = quotient*10;
        }
        for (int i = 0; i<length()-x.length()-1; i++)
        {
            while (x*quotient < *this || x*quotient == *this)
            {
                quotient.value[length()-x.length()-1-i]++;
            }
            quotient.value[length()-x.length()-1-i]--;
        }
        return quotient;
    }
}

ReallyLongInt ReallyLongInt::operator%(ReallyLongInt x)
{
    ReallyLongInt mod;
    ReallyLongInt i;
    i = 0;
    mod = 0;
    while (i*x < *this )
    {
        std::cout<<i*x<<std::endl;
        ++i;
    }
    --i;
    std::cout<<i<<std::endl;
    while (!(i*x+mod == *this))
    {
        ++mod;
    }

    return mod;

}

std::ostream& operator<<(std::ostream& out, const ReallyLongInt x)
{
    for (int i = MAX_LENGTH-1; i>=0; i--)
    {
        if (x.value[i] != 0)
        {
            for (int k = i; k>=0; k--)
            {
                out<<x.value[k];
            }
            i = -1;
        }
    }
    return out;
}

int ReallyLongInt::length()
{
    int len = 0;
    for (int i = MAX_LENGTH-1; i>=0; i--)
    {
        if (value[i] == 0)
        {
            len++;
        }
        else ( i = -1);
    }
    return (MAX_LENGTH-len);
}

ReallyLongInt::~ReallyLongInt()
{
    //dtor
}
