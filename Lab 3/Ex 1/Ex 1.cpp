#include "Math.h"
#include <iostream>
using namespace std;

int main()
{   
	math numar;
	cout <<"add(int,int) "<< numar.Add(3, 4) << endl;
	cout <<"add(int,int,int) "<< numar.Add(3, 4, 5) << endl;
	cout << "add(float, float) " << numar.Add(3.5, 4.2) << endl;
	cout << "3*float "<<numar.Add(3.5, 4.2, 5.1) << endl;
	cout <<"mul 2*int "<< numar.Mul(3, 4) << endl;
	cout <<"mul 3*int "<< numar.Mul(3, 4, 5) << endl;
	cout <<"mul 2*double "<< numar.Mul(3.5, 4.2) << endl;
	cout << "mul 3*double "<<numar.Mul(3.5, 4.2, 5.1) << endl;
	cout << "add ?* int "<<numar.Add(5, 1, 2, 3, 4, 5) << endl;
	cout << "add 2*char "<<numar.Add("Buna ", "ziua!") << endl;

	
}
