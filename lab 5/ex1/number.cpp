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