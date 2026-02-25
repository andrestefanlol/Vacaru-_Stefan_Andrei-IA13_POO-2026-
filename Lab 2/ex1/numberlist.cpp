
#include "numberlist.h"
#include <stdio.h>

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	;
	this->numbers[this->count] = x;
	this->count++;
	if (this->count >= 10)
		return false;
	return true;
}

void NumberList::Sort()
{	int ok = 0;
	do {
		ok = 0;
		for (int i = 0; i < this->count - 1; i++)
			if (this->numbers[i] > this->numbers[i + 1])
			{
				int aux = this->numbers[i];
				this->numbers[i] = this->numbers[i + 1];
				this->numbers[i + 1] = aux;
				ok = 1;
			}
	} while (ok!=0);
}

void NumberList::Print()
{
	for (int i = 0; i < this->count; i++)
		printf("%d ", this->numbers[i]);
	printf("\n");
}