#include <stdio.h>
#include "numberlist.h"

int main()
{
	NumberList lista;

	lista.Init();
	lista.Add(20);
	lista.Add(3);
	lista.Add(211);
	lista.Add(1);

	printf("Lista initiala: ");
	lista.Print();
	lista.Sort();

	printf("Lista sortata: ");
	lista.Print();

	return 0;
}