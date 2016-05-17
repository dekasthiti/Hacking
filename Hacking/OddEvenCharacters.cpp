#include "OddEvenCharacters.h"
#include <iostream> // cin, string
#include <vector>
#include <string> // getline
#include <sstream>

/*Objective 
Today we're expanding our knowledge of Strings and combining it with what we've already learned about loops. Check out the Tutorial tab for learning materials and an instructional video!

Task 
Given a string, S, of length N that is indexed from 0 to N - 1, print its even-indexed and odd-indexed characters as  space-separated strings on a single line (see the Sample below for more detail).

Note: 0 is considered to be an even index.

Input Format

The first line contains an integer, T (the number of test cases). 
Each line i of the T subsequent lines contain a String, S.

Constraints

1 <= T <= 10
2 <= S <= 10000

Output Format

For each String Sj (where 0<=j<=T-1 ), print Sj's even-indexed characters, followed by a space, followed by Sj's odd-indexed characters.

Sample Input

2
Hacker
Rank
Sample Output

Hce akr
Rn ak
Explanation

Test Case 0:  
 
The even indices are 0, 2, and 4, and the odd indices are 1, 3, and 5. We then print a single line of 2 space-separated strings; the first string contains the ordered characters from Sj's even indices (Hce), and the second string contains the ordered characters from Sj's odd indices (akr).

Test Case 1:  
 
The even indices are 0 and 2, and the odd indices are  1 and 3. We then print a single line of  space-separated strings; the first string contains the ordered characters from S's even indices (Rn), and the second string contains the ordered characters from S's odd indices (ak).*/

using namespace std;

void printOddEvenCharacters()
{
	vector<string> testStrings;
	string inputString;
	string oddString;
	string evenString;
	string s;
	// Repeat this for 1 <= T <= 10

	//cin >> inputString;
	getline(cin, inputString);
	stringstream ss(inputString); // copy input stream into a string stream
	
	while (getline(ss, s, ' '))  // instead of getline(cin, s, ' ') because this waits on the console forever
	{
		testStrings.push_back(s);
	}

	//split(ss, s, ' ') is possible with boost::split
	
	for (vector<string>::iterator i = testStrings.begin(); i != testStrings.end(); i++)
	{
		//cout << *i << endl;
		string t = *i;
		for (unsigned int i = 0; i < t.size(); i++)
		{
			if (i % 2 == 0)
			{
				evenString.push_back(t[i]);
			}
			else
			{
				oddString.push_back(t[i]);
			}
		}

	}
	
	cout << "\n" << evenString << " " << oddString << endl;
	
	return;
}