#define _CRT_SECURE_NO_WARNINGS
#include "number.h"
#include <cstring>
#include <iostream>
int ValoareBaza10(const char* s, int b) {
	int rez = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		int cifra = (s[i] >= 'A') ? (s[i] - 'A' + 10) : (s[i] - '0');
		rez = rez * b + cifra;
	}
	return rez;
}
char* IntLaString(int val, int b) {
	if (val == 0) { char* z = new char[2]; strcpy(z, "0"); return z; }
	int c = val, d = 0;
	while (c)
	{
		c /= b;
		d++;
	}
	char* r = new char[d + 1];
	r[d] = '\0';
	for (int i = d - 1; i >= 0; i--) {
		int cif = val % b;
		r[i] = (cif < 10) ? (cif + '0') : (cif - 10 + 'A');
		val /= b;
	}
	return r;
}
Number::Number(const char* value, int base)
{
	this->baza=base;
	this->value=new char[strlen(value)+1];
	strcpy(this->value,value);
}
Number::Number(int value)
{	
	this->baza = 10;
	this->value = IntLaString(value, this->baza);
}
Number::Number(const Number& other)
{	this->baza=other.baza;
	this->value=new char[strlen(other.value)+1];
	strcpy(this->value,other.value);
}
Number::Number(Number&& other)
{	this->baza=other.baza;
	this->value=other.value;
	other.value=nullptr;
	other.baza = 0;
}
Number::~Number()
{	delete[] this->value;
}
Number& Number::operator=(const Number& other)
{	
	if (this!=&other)
	{
		if (this->value != nullptr)
		{
			delete[] this->value;
		}
		this->baza=other.baza;
		if (other.value != nullptr)
		{
			this->value = new char[strlen(other.value) + 1];
			strcpy(this->value, other.value);
		}
		else {
			this->value = nullptr;
		}
	}
	return *this;
}
Number& Number::operator=(Number&& other)
{	
	if (this!=&other)
	{
		if (this->value != nullptr)
		{
			delete[] this->value;
		}
		this->baza=other.baza;
		this->value=other.value;
		other.value=nullptr;
		other.baza = 0;
	}
	return *this;
}
void Number::SwitchBase(int newBase)
{	
	int val=ValoareBaza10(this->value,this->baza);
	this->baza=newBase;
	delete[] this->value;
	this->value = IntLaString(val, this->baza);
}
Number& Number::operator=(int val)
{
	if (this->value != nullptr)
	{
		delete[] this->value;
	}
	this->value = IntLaString(val, this->baza);
	return *this;
}
Number& Number::operator=(const char* val)
{
	if (this->value != nullptr)
	{
		delete[] this->value;
	}
	this->value=new char[strlen(val)+1];
	strcpy(this->value,val);
	return *this;
}

Number operator+(const Number& a, const Number& b)
{
	int baza = (a.baza > b.baza) ? a.baza : b.baza;
	int val_a=ValoareBaza10(a.value,a.baza);
	int val_b=ValoareBaza10(b.value,b.baza);
	int suma=val_a+val_b;
	Number rezultat(suma);
	rezultat.SwitchBase(baza);
	return rezultat;
}
Number operator-(const Number& a, const Number& b)
{
	int baza = (a.baza > b.baza) ? a.baza : b.baza;
	int val_a = ValoareBaza10(a.value, a.baza);
	int val_b = ValoareBaza10(b.value, b.baza);
	int diferenta=val_a-val_b;
	Number rezultat(diferenta);
	rezultat.SwitchBase(baza);
	return rezultat;
}
Number& Number::operator+=(const Number& other)
{
	*this = *this + other;
	return *this;
	
}
bool Number::operator>(const Number& other)
{
	return ValoareBaza10(this->value, this->baza) > ValoareBaza10(other.value, other.baza);
}
bool Number::operator<(const Number& other)
{
	return ValoareBaza10(this->value, this->baza) < ValoareBaza10(other.value, other.baza);
}
bool Number::operator==(const Number& other)
{
	return ValoareBaza10(this->value, this->baza) == ValoareBaza10(other.value, other.baza);
}
bool Number::operator>=(const Number& other)
{
	return ValoareBaza10(this->value, this->baza) >= ValoareBaza10(other.value, other.baza);
}
bool Number::operator<=(const Number& other)
{
	return ValoareBaza10(this->value, this->baza) <= ValoareBaza10(other.value, other.baza);
}
Number& Number::operator--()
{
	int len=strlen(this->value);
	if (len>1)
	{
		char* new_value=new char[len];
		strcpy(new_value,this->value+1);
		delete[] this->value;
		this->value=new_value;
	}
	else
	{
		strcpy(this->value,"0");
	}
	return *this;
}
Number Number::operator--(int)
{
	int len=strlen(this->value);
	Number old(*this);
	
	if (len>1)
	{
		char* new_value=new char[len];
		strncpy(new_value,this->value,len-1);
		new_value[len-1]='\0';
		delete[] this->value;
		this->value=new_value;
	}
	else
	{
		strcpy(this->value,"0");
	}
	return old;
}
void Number::Print()
{
	std::cout<<this->value<<" (base "<<this->baza<<")\n";
}
int Number::GetDigitsCount()
{
	return strlen(this->value);
}
int Number::GetBase()
{
	return this->baza;
}
char Number::operator[](int index)
{
	if (index>=0 && index<GetDigitsCount())
	{
		return this->value[index];
	}
	return '\0';
}