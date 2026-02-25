#include "student.h"
#include <cstring>
#include <cstdio>
student::student()
{
    this->name = nullptr;
    this->mgrade = 1.0f;
    this->engrade = 1.0f;
    this->hgrade = 1.0f;
}
student::~student()
{
    if (this->name != nullptr)
        delete[] this->name;
}

void student::setname(const char* name)
{
    if (this->name != nullptr)
        delete[] this->name;
    int len = strlen(name) + 1;
    this->name = new char[len];
    strcpy_s(this->name, len, name);
}
const char* student::getname()
{
    return name;
}

void student::set_math(float grade)
{
    if (grade >= 1.0f && grade <= 10.0f) this->mgrade = grade;
}

float student::get_math()
{
    return this->mgrade;
}
void student::set_eng(float grade)
{
    if (grade >= 1.0f && grade <= 10.0f) this->engrade = grade;
}
float student::get_eng() { return this->engrade; }

void student::set_his(float grade)
{
    if (grade >= 1.0f && grade <= 10.0f) this->hgrade = grade;
}
float student::get_his() { return this->hgrade; }

float student::getaverage()
{
    return (this->mgrade + this->engrade + this->hgrade) / 3.0f;
}