#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <cmath>
using namespace std;

double closed_interval_rand(double x0, double x1)
{
	return x0 + (x1 - x0) * rand() / ((double) RAND_MAX);
}

int main (int argc, char const *argv[])
{
	cout << "Montekarlo realizacijos pradžia" << endl;
	cout << "(RANDOM SEARCH METHOD)" << endl;
	//kintamųjų apsirašymas
	double f, x; //funkcijos reikšmė ir argumentas x
	int n; //uždavinio dimensija
	double xsprendinys; //lala
	int fsprendinys; //uždavinio sprendinys
	double a, b, mas[100];
	

	
	cout << "Įveskite intervalo [a,b] rėžių reikšmes" <<endl;
	cout << "a = "; cin >>a;
	cout <<endl<< "b = "; cin >>b;
	cout <<endl<< "vektoriaus dimensiją (n): "; cin >>n;
	cout << endl;
	
	srand(time(0));
	
	cout << "x = ( ";
	for(int i = 0; i<n; i++)
	{
		mas[i] = closed_interval_rand(a, b);
	}
	
	for(int i = 0; i<n; i++)
	{
		cout<< mas[i]<< " ";
	}
	
	cout << ")"<<endl;
	return 0;
}
