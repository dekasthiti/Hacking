#include <iostream>
#include <vector>
#include <algorithm> // sorting?
#include "Vectors.h"  // My custom header


/*
You are given N integers.Sort the N integers and print the sorted order.
Store the N integers in a vector.Vectors are sequence containers representing arrays that can change in size.

Declaration:

vector<int>v; (creates an empty vector of integers)
Size:

int size=v.size();
Pushing an integer into a vector:

v.push_back(x);(where x is an integer.The size increases by 1 after this.)
Popping the last element from the vector:

v.pop_back(); (After this the size decreases by 1)
Sorting a vector:

sort(v.begin(),v.end()); (Will sort all the elements in the vector)
To know more about vectors, Click Here

Input Format

The first line of the input contains N where N is the number of integers. The next line contains  integers.
Constraints

, where N is the  integer in the vector.

Output Format

Print the integers in the sorted order one by one in a single line followed by a space.

Sample Input

5
1 6 10 8 4
Sample Output

1 4 6 8 10

Constraints
N >= 1, N <= 10^5
Vi >= 1, Vi <= 10^9
, where Vi is the ith integer in the vector.

*/
using namespace std;
void sortVector()
{
	unsigned int N; 
	unsigned int input;
	vector<unsigned int> V;

	// Read the input
	cout << "Enter the number of integers to sort (N): ";
	cin >> N;

	// Check the constraints on N
	if (N >= 1 && N <= 100000)
	{
		unsigned int inputCount = 0;
		cout << "Enter the integers to sort:" << endl;
		while (inputCount < N)
		{
			cin >> input;

			// Push it into the vector
			if (input >= 1 && input <= 1000000000)
			{
				V.push_back(input);
				inputCount++;
			}
			else
			{
				cout << "Failed constraint for Vi. Vi is " << input << " while Vi should be in [1, 1000000000] " << endl;
			}
		}

		if (!V.empty())
		{
			// Sort the vector
			sort(V.begin(), V.end()); // What is the complexity of this sort? O(N log N) : read std::sort. Alternative: stable_sort

			unsigned int i = 0;
			cout << "Sorted vector: " << endl;
			while (i < V.size() )
			{
				unsigned int tmp =  V[i++]; // Can't use pop_back because that will pop from the back of the vector
				cout << tmp << " ";
			}
		}
	}
	else
	{
		cout << "Failed constraint for N. N is " << N << " but N should be [1, 100000]. Quitting" << endl;
		return;
	}
	return;
}

class RobberSolution {
public:
	int rob(vector<int>& nums) {
		vector<int>::iterator itr1 = nums.begin();
		vector<int>::iterator itr2 = nums.begin() + 1;
		int maxAmount1 = 0;
		int maxAmount2 = 0;
		while (itr1 != nums.end()) {
			//if(itr1 != nums.end()){
			maxAmount1 += *itr1;
			if (itr1 + 1 == nums.end())
			{
				break;
			}
			itr1 = itr1 + 2;
		}


		while (itr2 != nums.end()) {
			//if(itr2 != nums.end()) {
			maxAmount2 += *itr2;
			if (itr2 + 1 == nums.end())
			{
				break;
			}
			itr2 = itr2 + 2;
		}
		//}
		return max(maxAmount1, maxAmount2);
	}
};

void main_Robber()
{
	int N;
	int cash;
	vector<int> cashBag;
	RobberSolution robSol;
	cout << "Enter number of houses" << endl;
	cin >> N;
	
	int i = 0;
	cout << "Enter cash stacked in each house " << endl;
	while (i < N)
	{
		//cin >> cash;
		//cashBag.push_back(cash);
		cashBag.push_back(i+1);
		i++;
	}
	
	cout << "Maximum amount stolen: " << robSol.rob(cashBag) ;
}