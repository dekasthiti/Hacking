// UniqueValue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>

#include "UniqueValue.h"
using namespace std;
int UniqueValue()
{
	long long unsigned N;
	unsigned int S, P, Q;
	unsigned int MAX = pow(2, 31); // UINT_MAX; // 2 ^ 31;
	long long unsigned uniqueCount = 0;
	vector<unsigned> a;
	cin >> N >> S >> P >> Q;
	cout << "\nStarted hacking!";
	cout << "\nValues read:" << N << "," << S << "," << P << "," << Q;

	a.push_back(S % (unsigned int)MAX);
	uniqueCount++;
	cout << "\n" << a[0];
	for (long long unsigned int i = 1; i < N; i++)
	{	
		a.push_back((a[i-1] * P + Q)% MAX);
		if (a[i] != a[i-1])
		{
			uniqueCount++;
		}
		//else
		//{
		//	break;
		//}
		cout << " " << a[i];
	}
	
	cout << "\nNumber of entries: " << a.size();
	cout << "\nUnique integers = " << uniqueCount;
    return 0;
}

