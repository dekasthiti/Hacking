/*
Objective
Today, we're building on our knowledge of Arrays by adding another dimension. Check out the Tutorial tab for learning materials and an instructional video!

Context
Given a  2D Array, :

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
We define an hourglass in  to be a subset of values with indices falling in this pattern in 's graphical representation:

a b c
  d
e f g
There are 16 hourglasses in A, and an hourglass sum is the sum of an hourglass' values.

Task
Calculate the hourglass sum for every hourglass in A, then print the maximum hourglass sum.

Input Format

There are 6 lines of input, where each line contains 6 space-separated integers describing 2D Array ; every value in  will be in the inclusive range of  to .

Constraints
-9 <= A[i][j] <= 9
0 <= i, j <= 5

Output Format

Print the largest (maximum) hourglass sum found in A.

Sample Input

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0
Sample Output

19
Explanation

contains the following hourglasses:

1 1 1   1 1 0   1 0 0   0 0 0
1       0       0       0
1 1 1   1 1 0   1 0 0   0 0 0

0 1 0   1 0 0   0 0 0   0 0 0
1       1       0       0
0 0 2   0 2 4   2 4 4   4 4 0

1 1 1   1 1 0   1 0 0   0 0 0
0       2       4       4
0 0 0   0 0 2   0 2 0   2 0 0

0 0 2   0 2 4   2 4 4   4 4 0
0       0       2       0
0 0 1   0 1 2   1 2 4   2 4 0
The hourglass with the maximum sum () is:

2 4 4
2
1 2 4
*/
#include <iostream>
#include <vector>
#include <algorithm> //sort
#include "Matrix.h"

using namespace std;
void printMaxHourGlassSum()
{
	vector< vector<int> > arr(6, vector<int>(6));

	// test input
	//arr = {
	//	{ 1, 1, 1, 0, 0, 0 },
	//	{ 0, 1, 0, 0, 0, 0 },
	//	{ 1, 1, 1, 0, 0, 0 },
	//	{ 0, 0, 2, 4, 4, 0 },
	//	{ 0, 0, 0, 2, 0, 0 },
	//	{ 0, 0, 1, 2, 4, 0 },
	//};

	arr = {
		{ -1, -1, 0, -9, -2, -2 },
		{ -2, -1, -6, -8, -2, -5 },
		{ -1, -1, -1, -2, -3, -4 },
		{ -1, -9, -2, -4, -4, -5 },
		{ -7, -3, -3, -2, -9, -9 },
		{ -1, -3, -1, -2, -4, -5 },
	};

		
	//for (int arr_i = 0; arr_i < 6; arr_i++) {
	//	for (int arr_j = 0; arr_j < 6; arr_j++) {
	//		cin >> arr[arr_i][arr_j];
	//	}
	//}

	vector<int> hourGlassSum;
	// The reason we are iterating from 0 to 3 is because otherwise hourGlassSum gets 0 inserted for 17 - 36 elements
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++)
		{
			vector<int> tmpHourGlass(7);
			int sum = 0;
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					// don't insert the 2 end elements of middle row
					// Account for 
					if ((i <= 3) &&
						(j <= 3) &&
						!(k == 1 && l == 0) &&
						!(k == 1 && l == 2))
					{
						int element = arr[i + k][j + l];

						// Check constraint on A[i][j]
						if (element >= -9 && element <= 9)
						{
							tmpHourGlass.push_back(element);
							sum = sum + element;
						}

					}
				}
			}
			hourGlassSum.push_back(sum);
		}
	}

	sort(hourGlassSum.begin(), hourGlassSum.end());

	cout << "\n Maximum hour glass sum is: " << hourGlassSum.back() << endl;
	return;
}

void rotate90()
{
	// Given an NXN (NXM?) matrix, rotate it by 90 degrees.
	// Worded differently, given an NXN matrix, traverse it spiralling inside

	// Trackers
	int left = 0, right = 0, top = 0, bottom = 0;

	// dir = 1: go right
	// dir = 2 : go down
	// dir = 3 : go left
	// dir = 4 : go up
	unsigned int dir = 1; 

	unsigned int N = 0;
	unsigned int M = 0;

	cout << "Enter the number of rows:";
	cin >> M;
	cout << "\nEnter the number of columns:";
	cin >> N;

	// Check for any constraints on M, N
	// if all constraints are satisfied
	// {

	// allocate space for matrix
	unsigned int **A;
	//A = (unsigned int**)malloc(M * N * sizeof(unsigned int)); // This will allocate a 1 D array

    // First, allocate a row of pointers
	A = (unsigned int**)malloc(M * sizeof(unsigned int*));

	// Then allocate pointers for each row
	for (unsigned int i = 0; i < M; i++)
	{
		A[i] = (unsigned int*)malloc(N * sizeof(unsigned int));
	}
	// if malloc is successful


	// Update the trackers
	left = 0;
	right = N-1;
	bottom = M-1;
	top = 0;

	for (int i = top; i <= bottom; i++)
	{
		//getline(cin, A[i]);
		for (int j = left; j <= right; j++)
		{
			//cin >> A[i][j];
			A[i][j] = i * N + j;

		}
	}

	//test
	for (int i = top; i <= bottom; i++)
	{
		for (int j = left; j <= right; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	// rotate
	while (top <= bottom && left <= right)
	{
		if (dir == 1)
		{
			for (int i = left; i <= right; i++)
			{
				cout << A[top][i] << " ";

			}
			dir = (dir + 1) % 5;
			top++;
		}

		if (dir == 2)
		{
			for (int i = top; i <= bottom; i++)
			{
				cout << A[i][right] << " ";
			}
			dir = (dir + 1) % 5;
			right--;
		}

		if (dir == 3)
		{
			for (int i = right; i >= left; i--)
				/* There was an interesting bug here. 
				The counter i was int, but left was unsigned int, so the comparison 
				i > = left was always true even when i was -1 or -2 .. because the comparison
				was promoting signed to unsigned?
				Always use the same types while comparing
				But what happens when both are unsigned?
				I saw that after i becomes 0, i >= left is always satisfied because i wraps around*/
			//for (unsigned int i = left; i < right; i++)
			{
				cout << A[bottom][i] << " ";
			}
			dir = (dir + 1) % 5;
			bottom--;
		}

		if (dir == 4)
		{
			for (int i = bottom; i >= top; i--)
			{
				cout << A[i][left] << " ";
			}
			dir = (dir + 1) % 5;
			left++;
		}
		dir++;
	}
	// }
	return;

}