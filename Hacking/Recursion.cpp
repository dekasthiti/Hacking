#include <iostream>
#include "Recursion.h"

using namespace std;

unsigned int factorial(unsigned int N)
{
	if (N == 0)
		return 1;
	else
	{
		return (N * factorial(N - 1));

	}
}
void factorial_main()
{
	unsigned int N;

	cout << "Enter N whose factorial should be computed: ";

	cin >> N;

	// Check N's constraints
	if (N >= 2 && N <= 12)
	{
		cout << "\nFactorial of " << N << " is: " << factorial(N);
	}
	else
	{
		cout << "\nFailed constraint on N. N is " << N << " while it should be in [2, 12]" << endl;
	}

}
