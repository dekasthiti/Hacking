#include "BitManipulation.h"
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
void decimalToBinary()
{
	unsigned int N; // Only positive number?
	cout << "\nEnter the number you wish to convert: ";
	cin >> N;

	stack<unsigned int> s;
	vector<unsigned int> consecutiveOnes;

	// Convert to Binary
	while (N != 0)
	{
		unsigned int rem = N % 2;
		s.push(rem);
		N = N >> 1;
	}
	cout << "\nBinary :";
	unsigned int oneCount = 0;
	unsigned int zeroCount = 0;
	while (s.size() != 0)
	{
		unsigned int tmp = s.top();
		if (tmp == 1)
		{
			oneCount++;
		}
		else
		{
			consecutiveOnes.push_back(oneCount); // this is not optimal. Consider input 16. You will be inserting for every 0.
			zeroCount++;
			oneCount = 0; //reset
		}
		cout << tmp;
		s.pop();
	}
	if (zeroCount == 0)
	{
		consecutiveOnes.push_back(oneCount); //if you never encountered a zero, you would never get a chance to push back
	}

	sort(consecutiveOnes.begin(), consecutiveOnes.end());

	cout << "\nMaximum consecutive ones: " << consecutiveOnes.back(); 
	
	return;
}