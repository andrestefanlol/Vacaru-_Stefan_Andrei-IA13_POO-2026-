#pragma once
#include <initializer_list>
#include <iostream>
using namespace std;
class Sort
{   
private:
    int* v;
    int count;
public:
    // add constuctors
	Sort(int count,int min, int max);
	Sort(initializer_list<int> list);
	Sort(int v[], int el);
    Sort(int count, ...);
    Sort(char s[]);
    ~Sort();
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
