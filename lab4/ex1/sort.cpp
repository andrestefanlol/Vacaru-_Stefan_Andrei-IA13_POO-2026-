#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
#include <iostream>
#include <cstring>
#include <random>
#include <stdarg.h>
#include <initializer_list>
using namespace std;
Sort::Sort(int count,int min,int max)
{
	Sort::v = new int[count];
	Sort::count = count;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(min, max);
	for (int i = 0; i < count; i++)
	{
		Sort::v[i] = dis(gen);
	}
}
Sort::Sort(initializer_list<int> list)
{
	Sort::v = new int[list.size()];
	Sort::count = list.size();
	int i = 0;
	for (int val:list)
	{
		Sort::v[i] = val;
		i++;
	}
}
Sort::Sort(int v[], int el)
{
	Sort::v = new int[el];
	Sort::count = el;
	for (int i = 0; i < el; i++)
	{
		Sort::v[i] = v[i];
	}
}
Sort::Sort(int count, ...)
{
	Sort::v = new int[count];
	Sort::count = count;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
	{
		Sort::v[i] = va_arg(args, int);
	}
	va_end(args);
}
Sort::Sort(char s[])
{
	Sort::count = 0;

	char* t = strtok(s, ",");
	while (t != NULL)
	{
		Sort::count++;
		
		t = strtok(NULL, ",");
	}
	char* t2 = strtok(s, ",");
	Sort::v = new int(Sort::count);
	int i = 0;
	while (t2 != NULL)
	{
		Sort::v[i] = atoi(t2);
		t2 = strtok(NULL, ",");
		i++;
	}
}
Sort::~Sort()
{
	delete[] Sort::v;
}
int Sort::GetElementsCount()
{
	return Sort::count;
}
void Sort::Print()
{
	for (int i = 0; i < Sort::count; i++)
	{
		cout << Sort::v[i] << " ";
	}
	cout << endl;
}
int Sort::GetElementFromIndex(int index)
{
	if (index < 0 || index >= Sort::count)
	{
		cout << "Indexul nu este valid" << endl;
		return -1;
	}
	return Sort::v[index];
}
void Sort::BubbleSort(bool ascendent)
{
	int ok = 0;
	do {
		ok = 0;
		for (int i = 0; i < Sort::count - 1; i++)
		{
			if ((ascendent && Sort::v[i] > Sort::v[i + 1]) || (!ascendent && Sort::v[i] < Sort::v[i + 1]))
			{
				int aux = Sort::v[i];
				Sort::v[i] = Sort::v[i + 1];
				Sort::v[i + 1] = aux;
				ok = 1;
			}
		}
	} while (ok != 0);
}
void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < Sort::count; i++)
	{
		int key = Sort::v[i];
		int j = i - 1;
		if (ascendent==true)
		{
			while (j >= 0 && Sort::v[j] > key)
			{
				Sort::v[j + 1] = Sort::v[j];
				j--;
			}
		}
		else
		{
			while (j >= 0 && Sort::v[j] < key)
			{
				Sort::v[j + 1] = Sort::v[j];
				j--;
			}
		}
		Sort::v[j + 1] = key;
	}
}
void Sort::QuickSort(bool ascendent)
{
	if (Sort::count <= 1)
		return;
	int* st = new int[Sort::count];
	int top = -1;
	st[++top] = 0;
	st[++top] = Sort::count - 1;

	while (top >= 0)
	{
		int high = st[top--];
		int low = st[top--];
		int pivot = Sort::v[high];
		int i = low - 1;
		for (int j = low; j <= high - 1; j++) 
		{
			bool mutat = false;
			if (ascendent) {
				if (Sort::v[j] < pivot) mutat = true;
			}
			else {
				if (Sort::v[j] > pivot) mutat = true;
			}
			if (mutat) {
				i++;
				int aux = Sort::v[i];
				Sort::v[i] = Sort::v[j];
				Sort::v[j] = aux;
			}
		}
		int temp = Sort::v[i + 1];
		Sort::v[i + 1] = Sort::v[high];
		Sort::v[high] = temp;
		int p = i + 1; 
		if (p - 1 > low) {
			st[++top] = low;
			st[++top] = p - 1;
		}
		if (p + 1 < high) {
			st[++top] = p + 1;
			st[++top] = high;
		}
	}
	delete[] st;
}