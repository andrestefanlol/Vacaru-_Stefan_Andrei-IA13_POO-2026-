#pragma once
class Number
{
private:
	char* value;
	int baza;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int value);
	Number(const Number& other);
	Number(Number&& other);
	~Number();
	Number& operator=(const Number& other);//copy
	Number& operator=(Number&& other);//move
	Number& operator=(int val);
	Number& operator=(const char* val);
	friend Number operator+(const Number& a, const Number& b);
	friend Number operator-(const Number& a, const Number& b);
	Number& operator+=(const Number& a);
	bool operator>(const Number& other);
	bool operator<(const Number& other);
	bool operator==(const Number& other);
	bool operator>=(const Number& other);
	bool operator<=(const Number& other);
	char operator[](int index); // caracter de la pozitia ceruta
	Number& operator--(); // elimina prima cifra
	Number operator--(int); // elimina ultima cifra
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base

};

