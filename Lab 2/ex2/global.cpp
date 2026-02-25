#include "global.h"
#include <cstring>

int comp_name(student* s1, student* s2)
{
    int res = strcmp(s1->getname(), s2->getname());
    if (res == 0) return 0;
    if (res > 0) return 1;
    return -1;
}

int comp_math(student* s1, student* s2)
{
    if (s1->get_math() == s2->get_math()) return 0;
    if (s1->get_math() > s2->get_math()) return 1;
    return -1;
}

int comp_eng(student* s1, student* s2)
{
    if (s1->get_eng() == s2->get_eng()) return 0;
    if (s1->get_eng() > s2->get_eng()) return 1;
    return -1;
}

int comp_his(student* s1, student* s2)
{
    if (s1->get_his() == s2->get_his()) return 0;
    if (s1->get_his() > s2->get_his()) return 1;
    return -1;
}

int comp_average(student* s1, student* s2)
{
    if (s1->getaverage() == s2->getaverage()) return 0;
    if (s1->getaverage() > s2->getaverage()) return 1;
    return -1;
}