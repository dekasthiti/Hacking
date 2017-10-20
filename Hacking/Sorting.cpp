#include "Sorting.h"
#include <stdlib.h>
#include <iostream>

using namespace std;
void merge(int input[], size_t left, size_t mid, size_t right);
void mergeSortRecursive(int input[], size_t left, size_t right);

void mergeSort(int input[])
{
	size_t inputLen = sizeof(input) / sizeof(input[0]);
	size_t left = 0;
	size_t right = inputLen;

	mergeSortRecursive(input, left, right);
	
}

void merge(int input[], size_t left, size_t mid, size_t right)
{
	size_t n1 = mid - left + 1; // +1 because ?
	size_t n2 = right - mid;

	// Can I do this? Isn't this dynamic?
	int *L = (int*)malloc(sizeof(int) * n1);
	int *R = (int*)malloc(sizeof(int) * n2);

	for (int i = 0; i < n1; i++)
	{
		L[i] = input[left + i];
	}
	for (int j = 0; j < n2; j++)
	{
		R[j] = input[mid + 1 + j];
	}

	int i = 0;
	int j = 0;
	int k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] < R[j])
		{
			input[k] = L[i];
			i++;
		}
		else
		{
			input[k] = R[j];
			j++;
		}
		k++;
	}

	// Why are we processing L first? This will be the case if L has elements left over and R is empty
	while (i < n1)
	{
		input[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		input[k] = R[j];
		j++;
		k++;
	}
}

void mergeSortRecursive(int input[], size_t left, size_t right)
{
	if (left < right)
	{
		size_t mid = (left + right - 1) / 2; // Why -1?

		mergeSortRecursive(input, left, mid);
		mergeSortRecursive(input, mid, right);
		merge(input, left, mid, right);
	}
}

int main_Sort() 
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	// TBD: Print the  given array:
	cout << "Given array  is " << endl;

	mergeSort(arr);

	// TBD: Print the sorted array
	cout << "Sorted array is" << endl;
	return 0;

}