#include "BitManipulation.h"
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <bitset>  // For: Binary representation
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

int setBit(int N, int i)
{
	if (i >= 0 && i < 32)
	{
		unsigned mask = 1 << (i);
		N = N | mask;
	}
	else
	{
		if (i < 0)
			cout << "\nCannot set bit < 0!!" << endl;
		else if(i > 31)
			cout << "\nCannot set bit > 31!" << endl;
	}

	return N;
}

void setBit_main()
{
	int N;
	cout << endl << "========Set Bit============" << endl;
	cout << "Enter a number: ";
	cin >> N;
	cout << "You entered 0x" << hex << N;
	bitset<32> x(N);
	cout << " (" << x << ")" << endl;

	int i;
	cout << "Enter the bit # you want to set: ";
	cin >> i;

	N = setBit(N, i);
	bitset<32> y(N);
	cout<< "Number after setting bit " << i << " is 0x" << hex << N << " (" << y << ")" << endl;
}

int getBit(int N, int i)
{
	int bit = 0;
	if (i >= 0 && i < 32)
	{
		int getMask = (1);
		bit = (N >> i) & getMask;
	}
	else
	{
		if (i < 0)
			cout << "\nCannot get bit < 0!!" << endl;
		else if (i > 31)
			cout << "\nCannot get bit > 31!!" << endl;
	}
	return bit;
}

void getBit_main()
{
	int N;
	cout << endl << "========Get Bit============" << endl;
	cout << "Enter a number: ";
	cin >> N;
	cout << "You entered 0x" << hex << N;
	bitset<32> x(N);
	cout << " (" << x << ")" << endl;

	int i;
	cout << "Enter the bit # you want to get ";
	cin >> i;

	int a = getBit(N, i);
	bitset<1> y(a);
	cout << i << "th bit is: " << y << endl;
}

int unsetBit(int N, int i)
{
	if (i >= 0 && i < 32)
	{
		N = N & ~(1 << i);
	}
	else
	{
		if (i < 0)
			cout << "\nCannot unset bit < 0 !!" << endl;
		else if (i >= 32)
			cout << "\nCannot unset bit >= 32 !!" << endl;
	}
	return N;
}

void unsetBit_main()
{
	int N;
	cout << endl << "========Unset Bit============" << endl;
	cout << "Enter a number: ";
	cin >> N;
	cout << "You entered 0x" << hex << N;
	bitset<32> x(N);
	cout << " (" << x << ")" << endl;

	int i;
	cout << "Enter the bit # you want to unset ";
	cin >> i;

	N = unsetBit(N, i);
	bitset<32> y(N);
	cout << "Number after unsetting bit " << i << " is 0x" << hex << N << " (" << y << ")" << endl;
}

int modifyBit(int N, int i)
{
	int j = getBit(N, i);

	if (j == 1)
		N = unsetBit(N, i);
	else
		N = setBit(N, i);

	return N;
}

void modifyBit_main()
{
	int N;
	cout << endl << "========Modify Bit============" << endl;
	cout << "Enter a number: ";
	cin >> N;
	cout << "You entered 0x" << hex << N;
	bitset<32> x(N);
	cout << " (" << x << ")" << endl;

	int i;
	cout << "Enter the bit # you want to modify ";
	cin >> i;

	N = modifyBit(N, i);
	bitset<32> y(N);
	cout << "Number after modifying bit " << i << " is 0x" << hex << N << " (" << y << ")" << endl;
}

int fitMinN(int N, int M, int j, int i)
{
	int oneMask = 0;
	int zeroMask = 0;
	// First, the unset mask for N
	for (int a = i; a <= j; a++)
	{
		oneMask = oneMask | (1 << a);
	}
	cout << "One mask: " << bitset<32>(oneMask) << endl;

	// Negate the mask to get inverse
	zeroMask = ~oneMask;
	cout << "Zero mask: " << bitset<32>(zeroMask) << endl;
	// Modify N
	N = N & zeroMask;
	cout << "After masking N from i to j: " << bitset<32>(N) << endl;

	// Shift M to j
	cout << "Shifting M to " << j << endl;
	M = M << j;
	cout << bitset<32>(M) << endl;

	// So you get only i to j of M
	//M = M & oneMask;
	//cout << "After masking M so we get only i to j of M " << bitset<32>(M) << endl;

	// Insert M in N
	N = N | M;
	cout << "After inserting M in N: " << bitset<32>(N) << endl;

	return N;
}

void fitMinN_main()
{
	int M, N, i, j;
	cout << endl << "========Fit M in N between j and i bit============" << endl;
	cout << "Enter N: ";
	cin >> N;
	bitset<32> n(N);
	cout << "You entered: " << N << "(" << n << ")" << endl;

	cout << "Enter M: ";
	cin >> M;
	bitset<32> m(M);
	cout << "You entered: " << M << "(" << m << ")" << endl;

	cout << "Enter j: ";
	cin >> j;

	cout << "Enter i: ";
	cin >> i;

	N = fitMinN(N, M, j, i);
	bitset<32> k(N);
	cout << "N after inserting M: " << k <<endl;
}