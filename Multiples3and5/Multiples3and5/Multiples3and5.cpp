// Multiples3and5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int sum = 0;
	for (int x = 1; x < 1000; x++)
	{
		if (x % 3 == 0 || x % 5 == 0) { sum += x; }

	}

	cout << sum << endl;

	//return 0;

}

