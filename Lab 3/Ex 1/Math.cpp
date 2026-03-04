#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <stdio.h>
#include <stdarg.h>
#include <cmath>
#include <cstring>


int math::Add(int a, int b)
{
	return a + b;
}
 int math::Add(int a, int b, int c)
{
	return a + b + c;
}
 int math::Add(double a, double b)
{
	 double sum = a + b;
	 int x = int(std::floor(sum));
	 return x;
}
 int math::Add(double a, double b, double c)
{
	 double sum = a + b+c;
	 int x = int(std::floor(sum));
	 return x;
}
 int math::Mul(int a, int b)
{
	return a * b;
}
 int math::Mul(int a, int b, int c)
{
	return a * b * c;
}
 int math::Mul(double a, double b)
{
	 double sum = a * b;
	 int x = int(std::floor(sum));
	 return x;
 }
 int math::Mul(double a, double b, double c)
{
	 double sum = a*b*c;
	 int x = int(std::floor(sum));
	 return x;
}
 int math::Add(int count, ...)
{	
	int sum = 0;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
	{
		sum += va_arg(args, int);
	}
	va_end(args);
	return sum;
}
 char* math::Add(const char* a, const char* b)
{	if (a == nullptr || b == nullptr)
	{
		return nullptr;
	}
	char* result =	new char [strlen(a) + strlen(b) + 1];
	strcpy(result, a);
	strcat(result, b);
	return result;
 }
