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
	double a, b, x0_min, x1_min, x0_max, x1_max, min, max, sum = 0, vid, mas[3];
	int k = 100000;
	
	srand(time(0));
	
	mas[0] = closed_interval_rand(-1.9, 1.9);
	mas[1] = closed_interval_rand(-1.1, 1.1);
	xsprendinys = sixhump(&mas[0]);
	min = xsprendinys;
	max = xsprendinys;
	
	for(int j = 1; j < k; j++)
	{
		
		mas[0] = closed_interval_rand(-1.9, 1.9);
		mas[1] = closed_interval_rand(-1.1, 1.1);
		xsprendinys = sixhump(&mas[0]);
		
		sum += xsprendinys;
		
		if(min > xsprendinys)
		{
			min = xsprendinys;
			x0_min = mas[0];
			x1_min = mas[1];
		}
		if(max < xsprendinys)
		{
			max = xsprendinys;
			x0_max = mas[0];
			x1_max = mas[1];
		}
		
	}
	cout<< "====================================="<<endl;
	cout << "F-jos minimumas yra "<< min <<endl;
	cout << "taške ("<< x0_min <<", "<<x1_min<< ")"<<endl;
	cout<< "-------------------------------------"<<endl;
	cout << "F-jos maximumas yra "<< max <<endl;
	cout << "taške ("<< x0_max <<", "<<x1_max<< ")"<<endl;
	cout<< "-------------------------------------"<<endl;
	cout << "F-jos vidurkis yra "<< (sum/k) <<endl;
	cout<< "====================================="<<endl;
	
	return 0;
}
