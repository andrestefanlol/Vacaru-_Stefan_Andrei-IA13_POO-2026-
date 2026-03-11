#include "sort.h"
#include <iostream>
using namespace std;

int main() {
    std::cout << "--- 1. Test Constructor Random & BubbleSort ---\n";
    // Creează o listă de 10 elemente, cu valori între 10 și 99
    Sort lista1(10, 10, 99);
    std::cout << "Initial: ";
    lista1.Print();

    lista1.BubbleSort(true); // true = crescător
    std::cout << "Dupa BubbleSort (crescator): ";
    lista1.Print();
    std::cout << "\n";


    std::cout << "--- 2. Test Constructor Initializer List & InsertSort ---\n";
    // Creează o listă folosind acolade
    Sort lista2 = { 50, 20, 80, 10, 30, 90, 40 };
    std::cout << "Initial: ";
    lista2.Print();

    lista2.InsertSort(false); // false = descrescător
    std::cout << "Dupa InsertSort (descrescator): ";
    lista2.Print();
    std::cout << "\n";


    std::cout << "--- 3. Test Constructor din Array & QuickSort ---\n";
    int array_existent[] = { 7, 1, 9, 3, 5, 8, 2 };
    // 7 este numărul de elemente din array_existent
    Sort lista3(array_existent, 7);
    std::cout << "Initial: ";
    lista3.Print();

    lista3.QuickSort(true); // true = crescător
    std::cout << "Dupa QuickSort (crescator): ";
    lista3.Print();
    std::cout << "\n";


    std::cout << "---";