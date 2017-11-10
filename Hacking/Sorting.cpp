#include "Sorting.h"
#include <stdlib.h>
#include <iostream>

using namespace std;
void merge(int input[], size_t left, size_t mid, size_t right);
void mergeSortRecursive(int input[], size_t left, size_t right);
void mergeSort(int input[]);
void bubbleSort(int input[]);
void insertionSort(int input[]);
void selectionSort(int input[]);
int partition(int input[], int start, int end, int pivot);
void quickSortRecursive(int input[], int start, int end);
void quickSort(int input[]);

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

	//delete L and R
	if (L)
	{
		delete L;
		L = nullptr;
	}

	if (R)
	{
		delete R;
		R = nullptr;
	}
}

void mergeSortRecursive(int input[], size_t left, size_t right)
{
	if (left < right)
	{
		size_t mid = left + (right - left) / 2; // To avoid overflow

		mergeSortRecursive(input, left, mid);
		mergeSortRecursive(input, mid, right);
		merge(input, left, mid, right);
	}
}

void bubbleSort(int input[])
{
	// If input is not empty
	size_t count = sizeof(input) / sizeof(input[0]);
	if (count > 1)
	{
		for (int i = 0; i < count; i++)
		{
			for (int j = 1; j <= count; j++)
			{
				if (input[i] > input[j])
				{
					int temp = input[i];
					input[i] = input[j];
					input[j] = temp;
				}
			}
		}
	}
}

void insertionSort(int input[])
{
	// Sorted Array on the left. Initialize to index 0
	// Unsorted array on the right. Initialize to index 0
	// For each element in the unsorted, compare with the highest index in sorted, if smaller, keep decrementing till you 
	// find the index whose element is smaller than the current element. 
	// Repeat till end of the array

	size_t elementCount = sizeof(input) / sizeof(input[0]);

	if (elementCount > 1)
	{
		for (int unsortedIndex = 1; unsortedIndex < elementCount; unsortedIndex++)
		{
			int sortedIndex = unsortedIndex - 1;
			int unsortedElement = input[unsortedIndex];
			{
				while ((unsortedElement < input[sortedIndex]) && sortedIndex >= 0)
				{
					// shift elements to the right
					input[unsortedIndex] = input[sortedIndex];
					input[sortedIndex] = unsortedElement;
					sortedIndex--;
				}

			}
		}
	}
	
}

void selectionSort(int input[])
{
	// Find the min element in the unsorted array
	// Swap the first element with the min element, increment the sorted index
	// For every iteration along the unsorted element, find the next min element and append it to the sorted array.
	// Maintain a sorted index, which is 1 less than the unsorted index

	size_t elementCount = sizeof(input) / sizeof(input[0]);
	int minElement = input[0];
	int minIndex = 0;
	for (int sortedIndex = 0; sortedIndex < elementCount; sortedIndex++)
	{
		for (int unsortedIndex = sortedIndex; unsortedIndex < elementCount; unsortedIndex++)
		{
			if (input[unsortedIndex] < minElement)
			{
				minElement = input[unsortedIndex];
				minIndex = unsortedIndex;
			}
		}

		// Swap new min with 
		int temp = input[sortedIndex];
		input[sortedIndex] = minElement;
		input[minIndex] = temp;

	}
}

int partition(int input[], int start, int end, int pivot)
{
	// initialize pIndex to start
	int pIndex = start;

	// initialize iterator i to pIndex + 1
	int iterator = pIndex + 1;

	// If value at pIndex is greater than that at i, swap value at i and pIndex and increment both
	while (iterator < end)
	{
		if (input[pIndex] > input[iterator])
		{
			int temp = input[pIndex];
			input[pIndex] = input[iterator];
			input[iterator] = temp;
			pIndex++;
		}
		iterator++;
	}
	// else, increment just i and continue to compare
	// repeat till i reaches end
	// Now swap pivot element and value at pIndex and return pIndex
	return pIndex;
}

void quickSortRecursive(int input[], int start, int end)
{
	int pivotElement = input[end];
	int pIndex = partition(input, start, end, pivotElement);
	if (start < end)
	{
		quickSortRecursive(input, start, pIndex);
		quickSortRecursive(input, pIndex + 1, end);
	}

}

void quickSort(int input[])
{
	size_t elementCount = sizeof(input) / sizeof(input[0]);

	quickSortRecursive(input, 0, elementCount);
}

int main_Sort() 
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	// TBD: Print the  given array:
	cout << "Given array  is " << endl;


	mergeSort(arr);

	bubbleSort(arr);

	insertionSort(arr);

	selectionSort(arr);

	quickSort(arr);

	// TBD: Print the sorted array
	cout << "Sorted array is" << endl;
	return 0;

}