#ifndef REALLYLONGINT_H
#define REALLYLONGINT_H
#define MAX_LENGTH 100
#define BASE 10
#include<iostream>
#include<cmath>
#include<string>

class ReallyLongInt
{
    public:
        ReallyLongInt();
        virtual ~ReallyLongInt();
        void operator=(std::string);
        void operator=(ReallyLongInt);
        void operator=(unsigned long long);
        ReallyLongInt operator+(ReallyLongInt);
        ReallyLongInt operator+(unsigned long long);
        ReallyLongInt operator-(ReallyLongInt);
        ReallyLongInt operator-(unsigned long long);
        void operator++();
        void operator--();
        ReallyLongInt operator*(ReallyLongInt);
        ReallyLongInt operator*(unsigned long long);
        bool operator<(ReallyLongInt);
        bool operator>(ReallyLongInt);
        bool operator==(ReallyLongInt);
        ReallyLongInt operator/(ReallyLongInt);
        ReallyLongInt operator%(ReallyLongInt);
        ReallyLongInt operator%(unsigned long long);
        friend std::ostream& operator<<(std::ostream&,const ReallyLongInt);

        int length();
        friend ReallyLongInt modExp(ReallyLongInt, ReallyLongInt, ReallyLongInt);
    private:
        int value[MAX_LENGTH];//the subscript of the array is the power of 10
};

#endif // REALLYLONGINT_H
