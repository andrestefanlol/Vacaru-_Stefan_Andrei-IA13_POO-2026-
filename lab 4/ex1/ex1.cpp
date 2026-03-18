#include "sort.h"
#include <iostream>
using namespace std;

int main() {
    cout << "1. Test Constructor Random & BubbleSort\n";
    Sort lista1(10, 10, 99);
    cout << "Initial: ";
    lista1.Print();

    lista1.BubbleSort(true);
    cout << "Dupa BubbleSort (crescator): ";
    lista1.Print();
    cout << "\n";

    cout << "2. Test Constructor Initializer List & InsertSort\n";
    
    Sort lista2 = { 50, 20, 80, 10, 30, 90, 40 };
    cout << "Initial: ";
    lista2.Print();
    lista2.InsertSort(false);
    cout << "Dupa InsertSort (descrescator): ";
    lista2.Print();
    cout << "\n";


    cout << "3. Test Constructor din Array & QuickSort\n";
    int array_existent[] = { 7, 1, 9, 3, 5, 8, 2 };
    Sort lista3(array_existent, 7);
    cout << "Initial: ";
    lista3.Print();
    lista3.QuickSort(true);
    cout << "Dupa QuickSort (crescator): ";
    lista3.Print();
    Sort s2 = lista1;
	s2.Print();
    return 0;
}
