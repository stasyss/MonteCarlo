#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <cmath>
#include <vector>

#define N 2
#define EPS 0.5
using namespace std;

struct tsk
	{
		double x0;
		double x1;
		double f;
	};

// Vektoriaus begalines (max) normos funkcijos deklaracija 
double Vector_Max_Norm(double v[], int n);

// Greiciausio nusileidimo (angl. Steepest Descent) metodo deklaracija
int  Steepest_Descent(double (*f)(double *), void (*df)(double *, double *),
     int (*stopping_rule)(double*, double, double*, double, double*, int, int), 
                          double a[], double *fa, double *dfa, double cutoff,
						double cutoff_scale_factor, double tolerance, int n);

// Generuoja atsitiktini realu skaiciu tarp dLow and dHigh
double GetRandomNumber(double dLow, double dHigh){
    return static_cast<double>(rand())/RAND_MAX*(dHigh-dLow) + dLow;
}

// Apskaiciuoja Six-hump Camel Back gradiento reiksme taske x
void SixHumpCamelBackGradient(double *x, double *fGrad){
    fGrad[0] = 8*x[0]-8.4*x[0]*x[0]*x[0]+2*x[0]*x[0]*x[0]*x[0]*x[0]+x[1];
    fGrad[1] = x[0]-8*x[1]+16*x[1]*x[1]*x[1];
}

// Algoritmo sustojimo salyga kontroliuojanti funkcija
int StoppingRule(double* a, double fa, double* x, double fx, double* dfa, int
iteration, int n){
	double fEps = abs(fx - fa); // Funkcijos reiksmiu skirtumas
	double xa[n];
	for(int i = 0; i < n; ++i) xa[i] = x[i]-a[i];
	double xEps = Vector_Max_Norm(xa, 2); // Argumento skirtumo norma
	double dfaEps = Vector_Max_Norm(dfa, 2); // Gradiento norma
	if(iteration > 3) 
		return -6;
	else
		return 0;
}	
	
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
	
	double region[] = {-1.9, 1.9, -1.1, 1.1};
	//double a[N] = {reiksmes[0].x0, reiksmes[0].x1}; // N-matis Vektorius
	double aaa[N];
	
	for(int ii=0; ii<3; ii++)
	{
		//cout<< "=============================================="<<endl;
		aaa[0] = reiksmes[ii].x0;
		aaa[1] = reiksmes[ii].x1;
		double fa = reiksmes[ii].x0; // Funkcijos reiksme pradiniame taske a
		double dfa[N]; 
		SixHumpCamelBackGradient(aaa, dfa); // Funkcijos gradiento reiksme taske a
		double cutoff = 1.0, cutoff_scale_factor = 1.0; // Pap. parametrai
		double tolerance = 0.01;
		int err = Steepest_Descent( sixhump, SixHumpCamelBackGradient, StoppingRule,
	    aaa, &fa, dfa, cutoff, cutoff_scale_factor, tolerance, N);
	    
	    	switch (err)
		{
			case 0:
				cout << "Success" << endl;
				break;
			case -1:
				cout << "In the line search three points are collinear." << endl; 
				break;
			case -2:
				cout << "In the line search the extremum of the parabola through the three points is a maximum." << endl;
				break;
			case -3:
				cout << "Int the line search the initial points failed to satisfy the condition that x1 < x2 < x3 and fx1 > fx2 < fx3." << endl;
				break;
			case -4:
				cout << "Not enough HEAP memory." << endl;
				break;
			case -5:
				cout << "The gradient evaluated at the initial point vanishes." << endl;
			case -6:
				cout << "Exceed maximal number of iterations." << endl;
			break;
		}
		//cout << "Greiciausio nusileidimo (angl. Steepest Descent) metodu" << endl;
		//cout << "surastas sprendinys yra:" << endl;
		//cout << "xMin = (" << aaa[0] << ", " << aaa[1] << ")" << endl;
		//cout << "f(xMin) = " << fa << endl;
		
		cout <<"x0="<< aaa[0] << " *** x1="<<aaa[1]<< " *** f="<<fa<<endl;
	
	}
	
	return 0;
}
