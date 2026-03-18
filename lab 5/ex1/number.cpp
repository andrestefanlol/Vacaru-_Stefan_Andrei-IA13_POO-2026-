#define _CRT_SECURE_NO_WARNINGS
#include "number.h"
#include <cstring>
#include <iostream>

Number::Number(const char* value, int base)
{	this->baza=base;
	this->value=new char[strlen(value)+1];
	strcpy(this->value,value);
}
Number::Number(int value)
{	this->baza=10;
if (value == 0)
	{
		this->value=new char[2];
		strcpy(this->value,"0");
		strcpy(this->value, "\0");
		return;
	}
	else
	{
		int copy=value;
		int digits=0;
		while (copy)
		{
			copy/=10;
			digits++;
		}
		this->value=new char[digits+1];
		this->value[digits]='\0';
		for (int i=digits-1;i>=0;i--)
		{
			this->value[i]=(value%10)+'0';
			value/=10;
		}
	}
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
int schimbare_baza(int value, int baza_veche, int baza_noua)
{
	int rezultat=0;
	int putere=1;
	while (value)
	{
		int cifra=value%baza_veche;
		rezultat+=cifra*putere;
		putere*=baza_noua;
		value/=baza_veche;
	}
	return rezultat;
}
void Number::SwitchBase(int newBase)
{	
	int val=schimbare_baza(atoi(this->value),this->baza,newBase);
	this->baza=newBase;
	int copy=val;
	int digits=0;
	while (copy)
	{
		copy/=this->baza;
		digits++;
	}
	delete[] this->value;
	this->value=new char[digits+1];
	this->value[digits]='\0';
	for (int i=digits-1;i>=0;i--)
	{
		int cifra=val%this->baza;
		if (cifra<10)
			this->value[i]=cifra+'0';
		else
			this->value[i]=cifra-10+'A';
		val/=this->baza;
	}
}
Number& Number::operator=(int val)
{
	if (this->value != nullptr)
	{
		delete[] this->value;
	}
	this->baza=10;
	if (val == 0)
	{
		this->value=new char[2];
		strcpy(this->value,"0");
		strcpy(this->value, "\0");
		return *this;
	}
	else
	{	int x=schimbare_baza(val,10,this->baza);
		int copy=x;
		int digits=0;
		while (copy)
		{
			copy/=this->baza;
			digits++;
		}
		this->value=new char[digits+1];
		this->value[digits]='\0';
		for (int i=digits-1;i>=0;i--)
		{
			int cifra=x%this->baza;
			if (cifra<10)
				this->value[i]=cifra+'0';
			else
				this->value[i]=cifra-10+'A';
			x/=this->baza;
		}
		
	}
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
	int baza = b.baza;
	if (a.baza < b.baza)
	{
		baza = b.baza;
	}

	int val_a=schimbare_baza(atoi(a.value),a.baza,10);
	int val_b=schimbare_baza(atoi(b.value),b.baza,10);
	int suma=val_a+val_b;
	Number rezultat(suma);
	rezultat.SwitchBase(baza);
	return rezultat;
}
Number operator-(const Number& a, const Number& b)
{
	int baza = b.baza;
	if (a.baza < b.baza)
	{
		baza = b.baza;
	}
	int val_a=schimbare_baza(atoi(a.value),a.baza,10);
	int val_b=schimbare_baza(atoi(b.value),b.baza,10);
	int diferenta=val_a-val_b;
	Number rezultat(diferenta);
	rezultat.SwitchBase(baza);
	return rezultat;
}
Number operator+=(const Number& a, const Number& b)
{
	int baza = b.baza;
	if (a.baza < b.baza)
	{
		baza = b.baza;
	}

	int val_a = schimbare_baza(atoi(a.value), a.baza, 10);
	int val_b = schimbare_baza(atoi(b.value), b.baza, 10);
	int suma = val_a + val_b;
	Number rezultat(suma);
	rezultat.SwitchBase(baza);
	return rezultat;
	
}
bool Number::operator>(const Number& other)
{
	int val_a=schimbare_baza(atoi(this->value),this->baza,10);
	int val_b=schimbare_baza(atoi(other.value),other.baza,10);
	return val_a>val_b;
}
bool Number::operator<(const Number& other)
{
	int val_a=schimbare_baza(atoi(this->value),this->baza,10);
	int val_b=schimbare_baza(atoi(other.value),other.baza,10);
	return val_a<val_b;
}
bool Number::operator==(const Number& other)
{
	int val_a=schimbare_baza(atoi(this->value),this->baza,10);
	int val_b=schimbare_baza(atoi(other.value),other.baza,10);
	return val_a==val_b;
}
bool Number::operator>=(const Number& other)
{
	int val_a=schimbare_baza(atoi(this->value),this->baza,10);
	int val_b=schimbare_baza(atoi(other.value),other.baza,10);
	return val_a>=val_b;
}
bool Number::operator<=(const Number& other)
{
	int val_a=schimbare_baza(atoi(this->value),this->baza,10);
	int val_b=schimbare_baza(atoi(other.value),other.baza,10);
	return val_a<=val_b;
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