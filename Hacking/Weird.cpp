#include <iostream>

using namespace std;

int AmIWeird() {
	int N;
	cin >> N;

	if (1 <= N && N<= 100)
	{
		if (N % 2 == 0)
		{
			if (N >= 2 && N <= 5)
			//if( 2 <= N <= 5) // This evaluates to true at 2 <=N and prints "Not Weird" for 6, 20, 22 etc. So, does it become an 'OR' effectively? Yes!! Be careful!!
				// Boolean statements like this cannot be compounded. Warning C4804: unsafe use of type 'bool' in operation
			{
				cout << "Not Weird";
			}
			else if (N >= 6 && N <= 20)
			//else if (6<= N <= 20)
			{
				cout << "Weird";
			}
			else  if (N > 20)
			{
				cout << "Not Weird";
			}
		}
		else
		{
			cout << "Weird";
		}
	}
	return 0;
}