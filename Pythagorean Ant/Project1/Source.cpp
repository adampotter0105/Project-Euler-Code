#include <iostream>
#include <iomanip>
#include <math.h>
#include <Windows.h>
#define PI 3.14159265358979
 
using namespace std;

double total = 0;
double probability = 0;
double xInt = 0.008;
double yInt = 0.008;
double iterations=0;

double add = 0;

int main()
{		cout<<"starting"<<endl;
	for (double y = 0; y < 4.0; y += yInt)
	{
		for (double x = 0; x < 3-0.75*y; x += xInt) {

			add = acos((pow(x, 2.0) - 3.0 * x + pow(y, 2.0) - 4.0 * y) / pow(  (pow(y,2.0)+pow(3-x,2.0)) * (pow(x, 2.0) + pow(4.0 - y, 2.0))  , 0.5) ) ;
			add = add/(2.0 * PI);
			//cout << add << endl;
			total += add;
			//cout << "x: " << x << ", y: " << y << endl;
			//cout << total << endl;
			iterations++;
		}

	}

	cout << setprecision(15)<< total << endl;
	cout << "Probability: " << setprecision(10) << total /iterations << endl;
	Sleep(100000);
	return  0;
}