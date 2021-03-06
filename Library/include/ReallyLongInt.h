#ifndef REALLYLONGINT_H
#define REALLYLONGINT_H
#define MAX_LENGTH 100
#define BASE 10
#include<iostream>
#include<cmath>
#include<string>
//Originally used to encrypt stuff but its not effecient enough to actually deal with large numbers
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
        friend unsigned long long gcd(unsigned long long, unsigned long long);
    private:
        int value[MAX_LENGTH];//the subscript of the array is the power of 10
};
unsigned long long gcd(unsigned long long, unsigned long long);
#endif // REALLYLONGINT_H
