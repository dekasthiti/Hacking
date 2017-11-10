#include <iostream>
#include "StaticConcepts.h" 

//1. Just including StaticConcepts.h twice: once, by StaticConcepts.cpp and another time by StaticConcepts2.cpp
//	the linker finds struct counter definition twice and complains: LNK4042: object specified more than once, extras ignored warning 
// LNK4042 warning goes away when StaticConcepts.h's Item Type is changed to C/C++ header instead of default C/C++ compiler: 
// src: https://stackoverflow.com/questions/3695174/visual-studio-2010s-strange-warning-lnk4042



//Btypedef struct counter myCounter2;

namespace staticConcepts
{
	// extern struct counter;
	//warning C4091 : 'extern ' : ignored on left of 'counter' when no variable is declared
	// 
	// warning goes away when I declare an instance of the struct
    struct counter myCounter2;
	
	//struct counter myCounter; 
	// This gives LNK 2005: struct counter staticConcepts::myCounter already defined in StaticConcepts.obj
	// LNK 1169: One or more multiply defined symbols found.
	// This means that it is ok to include the definition more than once using the same header file where the struct is defined
	// but it is not ok to declare the same instance.
	// It can also give the following compiler error first: C2086 counter staticConcepts::myCounter: redefinition

	// This error goes away when we declare it as extern.
	// Note: If it is declared as an extern here, but it is declared as a static in StaticConcepts.cpp, we get 
	// LNK 2001: unresolved external symbol error because static variables are not visible outside their files.
	extern struct counter myCounter;

	// On the other hand, if myCounter is declared as static in the other file, StaticConcepts.cpp, but not qualified as 
	// an extern here, it will be assumed this is a global. Also, when used (to print the values, for eg), without initializing
	// it, it will be automatically initialized to 0.
	//struct counter myCounter;

}

using namespace std;
using namespace staticConcepts;

int main_StaticConcepts2()
{
	cout << "Testing static concepts!" << endl;

	// Modify global variable myCounter and print the output
	myCounter2.a = 26;
	myCounter2.b = 'b';
	myCounter2.c = 3.0f;

	cout << "myCounter2 values are: myCounter2.a = " << myCounter2.a << ", myCounter2.b = " << myCounter2.b << ", myCounter2.c = " << myCounter2.c;

	//struct counter myCounter;
	// Declaring it here makes it a local variable. This compiles fine, but throws an exception at runtime
	// if it is used without initializing. Local structs are not initialized, only global and static are.

	cout << "On the other hand, myCounter (defined in another file StaticConcepts.cpp) values are: " << endl;
	cout << "myCounter values are: myCounter.a = " << myCounter.a << ", myCounter.b = " << myCounter.b << ", myCounter.c = " << myCounter.c;

	myStaticCounter.a = -1;
	myStaticCounter.b = 'y';
	myStaticCounter.c = -3.0;
	// if counter is qualified as static and instantiated as myStaticCounter in the header, each file that includes it has its own
	// copy of myStaticCounter and values are not seen across files. This file will see it as -1, y, -3, but StaticConcepts 
	// sees the automatically assigned values of 0,0,0

	return 0;
}