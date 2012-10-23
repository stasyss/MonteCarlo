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
	double a, b, ilg, mas[100];
	
	//random r1
	/*srand((unsigned)time(0));
	float random_integer; 
	random_integer = (rand()%10)+1;
	cout << random_integer << endl;
	*/
	
	cout << "Įveskite intervalo [a,b] rėžių reikšmes" <<endl;
	cout << "a = "; cin >>a;
	cout <<endl<< "b = "; cin >>b;
	cout <<endl<< "vektoriaus ilgis: "; cin >>ilg;
	cout << endl;
	
	srand(time(0));
	
	
	for(int i = 0; i<ilg; i++)
	{
		mas[i] = closed_interval_rand(a, b);
		cout << i<<": "<< mas[i] << endl;
	}
	return 0;
}
