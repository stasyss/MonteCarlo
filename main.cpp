#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <cmath>

#define MAX_MAS 1000000
#define EPS 0.01
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
	struct tsk
	{
		double x0;
		double x1;
		double f;
	};
	
	cout << "Montekarlo realizacijos pradžia" << endl;
	cout << "(RANDOM SEARCH METHOD)" << endl;
	//kintamųjų apsirašymas
	double f, x; //funkcijos reikšmė ir argumentas x
	int n; //uždavinio dimensija
	double xsprendinys; //lala
	int fsprendinys; //uždavinio sprendinys
	double a, b, x0_min, x1_min, x0_max, x1_max, min, max, sum = 0, vid;
	//double * taskai_x0, * taskai_x1, * f_reiksmes;
	tsk *reiksmes;
	double mas[3];
	
	
	reiksmes = (tsk*) malloc (MAX_MAS*sizeof(tsk));
	
	srand(time(0));
	
	/*
	mas[0] = closed_interval_rand(-1.9, 1.9);
	mas[1] = closed_interval_rand(-1.1, 1.1);
	xsprendinys = sixhump(&mas[0]);
	min = xsprendinys;
	max = xsprendinys;
	
	taskai_x0[0] = mas[0];
	taskai_x1[0] = mas[1];
	f_reiksmes[0] = xsprendinys;
	
	for(int j = 1; j < MAX_MAS; j++)
	{
		
		mas[0] = closed_interval_rand(-1.9, 1.9);
		mas[1] = closed_interval_rand(-1.1, 1.1);
		xsprendinys = sixhump(&mas[0]);
		
		taskai_x0[j] = mas[0];
		taskai_x1[j] = mas[1];
		f_reiksmes[j] = xsprendinys;
		
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
	cout << "F-jos vidurkis yra "<< (sum/MAX_MAS) <<endl;
	cout<< "====================================="<<endl;
	*/
//==============================================================================================	
	mas[0] = closed_interval_rand(-1.9, 1.9);
	mas[1] = closed_interval_rand(-1.1, 1.1);
	xsprendinys = sixhump(&mas[0]);
	min = xsprendinys;
	max = xsprendinys;
	
	reiksmes[0].x0 = mas[0];
	reiksmes[0].x1 = mas[1];
	reiksmes[0].f = xsprendinys;
	
	int j=1;
	int dydis = MAX_MAS;
	while(abs(-1.031628453 - xsprendinys) >EPS)
	{
		
		mas[0] = closed_interval_rand(-1.9, 1.9);
		mas[1] = closed_interval_rand(-1.1, 1.1);
		xsprendinys = sixhump(&mas[0]);
		
		reiksmes[j].x0 = mas[0];
		reiksmes[j].x1 = mas[1];
		reiksmes[j].f = xsprendinys;
		
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
		j++;	
	}
	
	cout<< "====================================="<<endl;
	cout << "F-jos minimumas yra "<< min <<endl;
	cout << "taške ("<< x0_min <<", "<<x1_min<< ")"<<endl;
	cout<< "-------------------------------------"<<endl;
	cout << "F-jos maximumas yra "<< max <<endl;
	cout << "taške ("<< x0_max <<", "<<x1_max<< ")"<<endl;
	cout<< "-------------------------------------"<<endl;
	cout << "F-jos vidurkis yra "<< (sum/(j-1)) <<endl;
	cout<< "-------------------------------------"<<endl;
	cout << "Ciklas prasuktas "<< (j-1)<<" kartų" <<endl;
	cout<< "====================================="<<endl;
	
	
	free (reiksmes);

	
	return 0;
}
