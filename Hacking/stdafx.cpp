// stdafx.cpp : source file that includes just the standard includes
// Hacking.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include "UniqueValue.h"
#include "DataTypesFormatting.h"
#include "Weird.h"
#include "Strings.h"
#include "OddEvenCharacters.h"
#include "Vectors.h"
#include "Recursion.h"
#include "Matrix.h"
#include "BitManipulation.h"
#include "Inheritance.h"
#include "LinkedLists.h"
#include "StacksAndQueues.h"
#include "Trees.h"
#include "VirtualFunctions.h"
#include "StaticConcepts.h"
#include "Memory.h"
#include "Sorting.h"

#include <iostream>
using namespace std;
// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
int main()
{
	//UniqueValue();
	//DataTypeFormat();
	//AmIWeird();
	//isUnique("zebra");
	//isUnique("caterpillar");
	//printOddEvenCharacters();

	//// 10th May 2016
	//// Time this
	//isPermutationMap("caterpillar", "catcatcatar");
	//isPermutationMap("caterpillar", "caterpillar");

	//// Time this
	//isPermutationHashTable("caterpillar", "catcatcatar");
	//isPermutationHashTable("caterpillar", "caterpillar");

	//isPermutationHashSet("caterpillar", "catcatcatar");
	//isPermutationHashSet("caterpillar", "caterpillar");

	//isPermutationBitSet("caterpillar", "catcatcatar");
	//isPermutationBitSet("caterpillar", "caterpillar");

	//isPermutationBoolVector("caterpillar", "catcatcatar");
	//isPermutationBoolVector("caterpillar", "caterpillar");

	//// 15th May 2016: VMWare 
	//subStringFrequency();

	//// 16th May, 2016
	//sortVector();
	//factorial_main();

	//printMaxHourGlassSum();

	//decimalToBinary();

	////17th May, 2016
	//rotate90();
	//main_inheritance();
	//main_LinkedList();

	//23rd May, 2016
	//main_palindrome();

	// 26th May, 2016
	//main_Tree();

	// TBD:
	//main_Robber();

	// 9th June, 2016
	//setBit_main();
	//getBit_main();
	//unsetBit_main();
	//modifyBit_main();
	//fitMinN_main();
	

   // 9th May, 2017
	//main_VirtualFunction();

	// 13th May, 2017
	 main_StaticConcepts();
	 main_StaticConcepts2();

	// 1st Sep, 2017
	// main_Strings();

	// 26th Sep, 2017
	//main_Memory();

	// 20th Oct, 2017
	//main_Sort();


	// How much data can I allocate on stack
	//int a[1024 * 1024 * 256 ];  // 2^31 - 1 elements = 2^31 - 1 * sizeof(int) bytes: when compiled as 32 bit app or 64 bit app
	// Afte allocating 1GB ints, if I try to allocate more static data, will I be able to ?

	//int b[1024 * 1024 ];

	// if b is declared as an array of 1024 * 1024 * 256 ints as an array before it, along with a, we get a 'automatic allocation cannot exceed 2GB
	// The other error is: array allocation cannot exceed 0x7fffffff. Individual array allocation cannot exceed 2^31 - 1. This is whether 
	// binary is compiled as 32 bit app or 64 bit app. Looks like stack space is bounded by 2G limit. 2G limit is checked against at 
	// compile time and okayed, but get stack overflow at runtime
	long long c = 0;

	//for (int i = 0; i < 1024 * 1024 ; i++)
	//{
	//	a[i] = i;
	//	//b[i] = i;
	//	c += a[i]; // *b[i];
	//}
	size_t largeSize =(size_t) 1024 * 1024 * 1024 * 4 + 1;
	int* d = (int*)malloc(largeSize);
	// with this size = 1024 * 1024 * 1024 * 64, I get a warning C4307 : '*' integral constant overflow and a null pointer at runtime

	if (d != nullptr)
	{
		cout << "Allocated " << largeSize << " on heap" << endl;
	}
}