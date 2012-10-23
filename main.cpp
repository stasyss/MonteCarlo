#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <cmath>
using namespace std;

double sixhump(double * x)
{
	double f = (4-2.1*x[0]*x[0]+pow(x[0], 4.0)/3)*x[0]*x[0]+x[0]*x[1]+(-4+4*x[1]*x[1])*x[1]*x[1];
	return f;
}

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
	int k = 100;
	

	
	cout << "Įveskite intervalo [a,b] rėžių reikšmes" <<endl;
	cout << "a = "; cin >>a;
	cout <<endl<< "b = "; cin >>b;
	cout <<endl<< "vektoriaus dimensiją (n): "; cin >>n;
	cout << endl;
	
	srand(time(0));
	
	
	for(int i = 0; i<n; i++)
	{
		mas[i] = closed_interval_rand(a, b);
	}
	
	
	
	cout << "x = ( ";
	for(int i = 0; i<n; i++)
	{
		cout<< mas[i]<< " ";
	}
	
	cout << ")"<<endl;
	
	//mas[0] = -0.089842;
	//mas[1] = 0.712656;
	cout << "Six hump funkcijos reikšmė šiame taške: " << sixhump(&mas[0])<< endl;
	
	return 0;
}
