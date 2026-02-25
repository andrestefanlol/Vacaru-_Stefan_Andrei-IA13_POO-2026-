#include <cstdio>
#include "student.h"
#include "global.h"

int main()
{
    student s1;
    s1.setname("Popescu Ion");
    s1.set_math(9.5f);
    s1.set_eng(8.0f);
    s1.set_his(7.5f);
    student s2;
    s2.setname("Ionescu Maria");
    s2.set_math(10.0f);
    s2.set_eng(9.0f);
    s2.set_his(8.5f);
   
    printf("student 1: %s (Medie: %.2f)\n", s1.getname(), s1.getaverage());
    printf("student 2: %s (Medie: %.2f)\n\n", s2.getname(), s2.getaverage());
    printf("Comparatie Nume: %d\n", comp_name(&s1, &s2));
    printf("Comparatie Mate: %d\n", comp_math(&s1, &s2));
    printf("Comparatie Medie: %d\n", comp_average(&s1, &s2));
    return 0;
}