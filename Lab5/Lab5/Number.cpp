#include "Number.h"
#include <iostream>

int Number::charToDigit(char c) {
	if (c >= '0' && c <= '9') return c - '0';
	if (c >= 'A' && c <= 'F') return c - 'A' + 10;
	return -1; // Invalid character
}

char Number::digitToChar(int digit) {
	if (digit >= 0 && digit <= 9) return '0' + digit;
	if (digit >= 10 && digit <= 15) return 'A' + (digit - 10);
	return '?'; // Invalid digit
}

Number::Number(const char* value, int base)
{
	long long cnt = 0, num = 0, base_power = 1;
	for (int i = 0; value[i] != '\0'; i++)
		cnt++, base_power *= base;
	base_power /= base;
	this->value = new char[cnt];
	for (int i = 0; value[i] != '\0'; i++)
		this->value[i] = value[i],
		num += charToDigit(value[i]) * base_power,
		base_power /= base;
	this->base = base;
	this->lenght = cnt;
	this->base10_value = num;
}

Number::Number(int value)
{
	long long cvalue = value, cnt = 0;
	this->base = 10;
	this->base10_value = value;
	if (value == 0) {
		this->value = new char[1];
		this->value[0] = '0';
		this->lenght = 1;
		return;
	}
	while (value) {
		value /= 10;
		cnt++;
	}
	this->lenght = cnt;
	this->value = new char[cnt];
	cnt--;
	while (cvalue) {
		this->value[cnt] = cvalue % 10;
		cvalue /= 10;
	}
}

Number::~Number()
{
	delete[] value;
}

Number::Number(const Number& other) {
	this->base = other.base;
	this->lenght = other.lenght;
	this->base10_value = other.base10_value;

	this->value = new char[lenght + 1];
	for (int i = 0; i < lenght; i++) {
		this->value[i] = other.value[i];
	}
	this->value[lenght] = '\0';
}

Number::Number(Number&& other) noexcept {
	this->base = other.base;
	this->lenght = other.lenght;
	this->base10_value = other.base10_value;
	this->value = other.value;

	other.value = 0;
	other.lenght = 0;
}

Number& Number::operator=(int value) {
	this->base = 10;
	this->base10_value = value;

	long long temp = value, cnt = 0;
	if (value == 0) cnt = 1;
	while (temp) {
		temp /= 10;
		cnt++;
	}

	delete[] this->value;
	this->value = new char[cnt + 1];
	this->lenght = cnt;

	temp = value;
	for (int i = cnt - 1; i >= 0; i--) {
		this->value[i] = '0' + (temp % 10);
		temp /= 10;
	}
	this->value[cnt] = '\0';

	return *this;
}

Number& Number::operator=(const char* value) {
	int newLength = 0;
	while (value[newLength] != '\0') newLength++;

	delete[] this->value;
	this->value = new char[newLength + 1];
	this->lenght = newLength;

	for (int i = 0; i < newLength; i++) {
		this->value[i] = value[i];
	}
	this->value[newLength] = '\0';

	return *this;
}

Number& Number::operator=(const Number& other) {
	if (this != &other) {
		delete[] this->value;

		this->base = other.base;
		this->lenght = other.lenght;
		this->base10_value = other.base10_value;

		this->value = new char[lenght + 1];
		for (int i = 0; i < lenght; i++) {
			this->value[i] = other.value[i];
		}
		this->value[lenght] = '\0';
	}
	return *this;
}

Number& Number::operator=(Number&& other) noexcept {
	if (this != &other) {
		delete[] this->value;

		this->base = other.base;
		this->lenght = other.lenght;
		this->base10_value = other.base10_value;
		this->value = other.value;

		other.value = 0;
		other.lenght = 0;
	}
	return *this;
}


bool Number::operator<(const Number& n) const
{
	return (this->base10_value < n.base10_value);
}

bool Number::operator>(const Number& n) const
{
	return (this->base10_value > n.base10_value);
}

bool Number::operator<=(const Number& n) const
{
	return (this->base10_value < n.base10_value || this->base10_value == n.base10_value);
}

bool Number::operator>=(const Number& n) const
{
	return (this->base10_value > n.base10_value || this->base10_value == n.base10_value);
}

bool Number::operator==(const Number& n) const
{
	return (this->base10_value == n.base10_value);
}

char Number::operator[](int index) const
{
	if (index < lenght && index >= 0)
		return value[index];
	return '\0';
}

void Number::operator--()
{
	long long base_power = 1, digit = charToDigit(value[0]);
	for (int i = 0; i < lenght; i++)
		value[i] = value[i + 1],
		base_power *= base;
	lenght--;
	base_power /= base;
	base10_value -= digit * base_power;
}

void Number::operator--(int)
{
	base10_value -= long long(charToDigit(value[lenght - 1]));
	value[lenght - 1] = '\0';
	lenght--;
}

void Number::SwitchBase(int newBase)
{
	long long cbase10_value = this->base10_value, cnt = 0;
	while (cbase10_value) {
		cbase10_value /= newBase;
		cnt++;
	}
	cbase10_value = this->base10_value;
	delete[] this->value;
	this->value = new char[cnt];
	this->lenght = cnt;
	this->base = newBase;
	cnt--;
	while (cbase10_value) {
		this->value[cnt] = digitToChar(cbase10_value % newBase);
		cbase10_value /= newBase;
		cnt--;
	}
}

void Number::Print()
{
	for (int i = 0; i < lenght; i++)
		std::cout << value[i];
	std::cout << std::endl;
}

int Number::GetDigitsCount()
{
	return lenght;
}

int Number::GetBase()
{
	return base;
}

Number operator+(const Number& n1, const Number& n2)
{
	long long new_value = n1.base10_value + n2.base10_value;
	Number newNum(new_value);
	newNum.SwitchBase(std::max(n1.base, n2.base));
	return newNum;
}

Number operator-(const Number& n1, const Number& n2)
{
	long long new_value = n1.base10_value - n2.base10_value;
	Number newNum(new_value);
	newNum.SwitchBase(std::max(n1.base, n2.base));
	return newNum;
}

Number operator+=(Number& n1, const Number& n2)
{
	n1.base10_value += n2.base10_value;
	n1.SwitchBase((n1.base > n2.base) ? n1.base : n2.base);
	return n1;
}

Number operator-=(Number& n1, const Number& n2)
{
	n1.base10_value -= n2.base10_value;
	n1.SwitchBase((n1.base > n2.base) ? n1.base : n2.base);
	return n1;
}
