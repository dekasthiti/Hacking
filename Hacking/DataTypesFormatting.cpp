#include <iostream>
#include <iomanip>
#include <limits>
#include <string>


#include "DataTypesFormatting.h"

using namespace std;

int DataTypeFormat() {
	int i = 4;
	double d = 4.0;
	string s = "HackerRank ";

	// Declare second integer, double, and String variables.
	int i2;
	double d2;
	string s2;
	cout << fixed;


	// Read and save an integer, double, and String to your variables.
	cin >> i2;
	cin >> d2;
	// This doesn't work in HackerRank, works here
	getline(cin, s2);

	// This works in HackerRank, doesn't work here
	if (getline(cin >> ws, s2)) { // eat whitespace
		getline(cin, s2);
	}

	// Print the sum of both integer variables on a new line.
	cout << "\n" << i + i2;

	// Print the sum of the double variables on a new line.
	double tmp = d + d2;
	cout << "\n" << setprecision(3) << tmp;

	// Concatenate and print the String variables on a new line
	// The 's' variable above should be printed first.
	cout << "\n" << s + s2;

	return 0;
}