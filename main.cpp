#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <cmath>
#include <vector>

#define EPS 0.00001
using namespace std;

struct tsk
	{
		double x0;
		double x1;
		double f;
	};
	
	
void swap(tsk *x,tsk *y)
{
	tsk temp;
	temp=*x;
	*x = *y;
	*y = temp;
}

void heapsort(tsk *a,int n)
{
	int i,s,f;
	for(i=1;i< n;++i)
	{
		s=i;
		f=(s-1)/2;
		while( a[f].f< a[s].f)
		{
			swap(&a[f],&a[s]);
			s=f;
			if(s==0)
			break;
			f=(s-1)/2;
		}
	}
	for(i=n-1;i>=1;--i)
	{
		swap(&a[0],&a[i]);
		f=0;
		s=1;
		if(i==1)
		break;
		if(i>2)if(a[2].f>a[1].f)s=2;
		while( a[f].f< a[s].f )
		{
			swap(&a[f],&a[s]);
			f=s;
			s=2*f+1;
			if(i>s+1 )if(a[s+1].f>a[s].f)s=s+1;
			if (s>=i)
			break;
		}
	}
}

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
	double a, b, x0_min, x1_min, x0_max, x1_max, min, max, sum = 0, vid;
	//double * taskai_x0, * taskai_x1, * f_reiksmes;
	//tsk *reiksmes;
	tsk temp;
	double mas[3];
	
	vector <tsk> reiksmes(0);	
	
	//reiksmes = (tsk*) malloc (MAX_MAS*sizeof(tsk));
	
	
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
	
	temp.x0 = mas[0];
	temp.x1 = mas[1];
	temp.f = xsprendinys;
	
	reiksmes.push_back(temp);
	
	int j=1;
	while(abs(-1.031628453 - xsprendinys) >EPS)
	{
		
		mas[0] = closed_interval_rand(-1.9, 1.9);
		mas[1] = closed_interval_rand(-1.1, 1.1);
		xsprendinys = sixhump(&mas[0]);
		
		temp.x0 = mas[0];
		temp.x1 = mas[1];
		temp.f = xsprendinys;
	
		reiksmes.push_back(temp);
		
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
	
	
	//free (reiksmes);

	heapsort(&reiksmes[0],(j-1));
	
	cout<< "=============================================="<<endl;
	cout << "Trys taškai su minimaliomis f-jos reikšmėmis" <<endl;
	for(int i=0; i<3; i++)
	{
		cout <<"x0="<< reiksmes[i].x0 << " *** x1="<<reiksmes[i].x1<< " *** f="<<reiksmes[i].f<<endl;
	}
	cout<< "=============================================="<<endl;
	
	return 0;
}
