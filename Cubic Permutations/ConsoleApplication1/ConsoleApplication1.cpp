// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int digits[100]; //array to hold digits of test number
int digitsTest[100];
int testNum = 345;
int matches = 0;
 double temp = 0;
 double temp2 = 0;
 string tempS; 


bool testNegs(int size)
{
	bool allNeg = true;
	for (int y = 0; y < size; y++) {
		if (digitsTest[y] != -1) { allNeg = false; }
	}
	return allNeg;
}



int check(int x, int size) {
	//Place digits into array
	for (int f = 0; f < 25; f++) { digits[f] = -1; }//fill with -1's
	for (int f = 0; f < 25; f++) { digitsTest[f] = -1; }//fill with -1's
	//Cast into Array
	temp = x*x*x;
	for (int p = 0; p < size; p++)
	{
		temp2 = temp / (pow(10, size - p - 1));
		
		digits[p] = (int) floor(temp2);
		temp -= digits[p] * pow(10, size - p - 1);
	}


	/*for (int p = 0; p < size; p++)
	{

		cout << digits[p] << endl;

	}*/
	
	matches = 0;

	//Find Combo
	for (int g = testNum; ceil(log10((g*g*g) + 1)) == size; g++) {
		//Cast into Array
		temp = g*g*g;
		for (int p = 0; p < size; p++)
		{
			temp2 = temp / (pow(10, size - p - 1));

			digitsTest[p] = (int)floor(temp2);
			temp -= digitsTest[p] * pow(10, size - p - 1);
		}

		/*
		cout << (g*g*g) << endl;
		for (int f = 0; f < size; f++) {
			cout << digitsTest[f] << endl; Sleep(100);
		}*/

		for (int p = 0; p < size; p++) {

			for (int e = 0; e < size; e++) {
				if (digits[p] == digitsTest[e]) {
					digitsTest[e] = -1; break;
				}
			}

		}
		if (testNegs(size)) { matches++; if (testNum != g) { cout << testNum << ", " << g << endl; } }

	}

	//Enough matches
	if (matches > 1) { cout << matches << endl; }
	if(matches==5)
	{
		cout << "five matches!" << endl;
		return 1;
	}

	else { return 0; }
}



int permutation() {

	int size = 0; temp = testNum*testNum*testNum;
	do {
		++size;
		temp /= 10;
	} while (temp>1);


	while (check(testNum, size) == 0) {
		testNum++;//cycle through numbers
		size = 0; temp = testNum*testNum*testNum;
			do {
				size++;
				temp /= 10;
			} while (temp>1.00000000000000000000001);

	}

	return testNum;
} 



int main()
{


		cout << permutation() << endl;

    return 0;
}

