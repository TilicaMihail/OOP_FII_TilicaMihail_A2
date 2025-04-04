#pragma once
class Number {
    char* value;
    long long lenght, base, base10_value;

    int charToDigit(char c);

    char digitToChar(int digit);

public:
    Number(const char* value, int base); 
    Number(int value);
    ~Number(); 

    Number(const Number& other);

    Number(Number&& other) noexcept;

    Number& operator=(int value);

    Number& operator=(const char* value);

    Number& operator=(const Number& other);

    Number& operator=(Number&& other) noexcept;

    friend Number operator+(const Number& n1, const Number& n2);

    friend Number operator-(const Number& n1, const Number& n2);

    friend Number operator+=(Number& n1, const Number& n2);

    friend Number operator-=(Number& n1, const Number& n2);

    bool operator<(const Number& n) const;
    bool operator>(const Number& n) const;
    bool operator<=(const Number& n) const;
    bool operator>=(const Number& n) const;
    bool operator==(const Number& n) const;

    char operator[](int index) const;

    void operator--();

    void operator--(int);

    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount(); // returns the number of digits for the current number
    int GetBase(); // returns the current base
};


