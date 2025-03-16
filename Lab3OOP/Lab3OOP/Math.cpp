#include "Math.h"
#include <cstdarg>  
#include <cstring>  
#include <cstdlib>

int Math::Add(int a, int b)
{
    return a + b;
}

int Math::Add(int a, int b, int c)
{
    return a + b + c;
}

int Math::Add(double a, double b)
{
    return a + b;
}

int Math::Add(double a, double b, double c)
{
    return a + b + c;
}

int Math::Mul(int a, int b)
{
    return a * b;
}

int Math::Mul(int a, int b, int c)
{
    return a * b * c;
}

int Math::Mul(double a, double b)
{
    return a * b;
}

int Math::Mul(double a, double b, double c)
{
    return a * b * c;
}

int Math::Add(int count, ...)
{
    va_list args;
    va_start(args, count);
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}

char* Math::Add(const char* a, const char* b)
{
    if(!a || !b)
        return nullptr;

    size_t l1 = strlen(a);
    size_t l2 = strlen(b);
    size_t l3 = l1 + l2 + 1;
    char* rez = (char*)malloc(l3);
    if (!rez)
        return nullptr;
    strcpy_s(rez, l3, a);
    strcat_s(rez, l3, b);

    return rez; 

}
