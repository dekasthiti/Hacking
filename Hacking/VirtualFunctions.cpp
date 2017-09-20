#include <iostream>
#include "VirtualFunctions.h"

using namespace std;

class A 
{
public:
	virtual ~A() { cout << "\n" << "Inside A's destructor " << endl; } // if destructor is declared as private, get a A:~A cannot access private member declared in class A

	void printMe()
	{
		cout << "You are in A! " << endl;
	}
	virtual void singMe()
	{
		cout << "AAAAAAA";
	}
};
class B : public A // Inheritance is private by default. If you don't specify public, conversion of A* to B* is allowed but inaccessible
{
public:
    ~B() { cout << "\n" << "Inside B's destructor" << endl; }
	void printMe()
	{
		cout << "You are in B! " << endl;
	}
	void singMe()
	{
		cout << "BABABABAAA";
	}

	//if virtual desctructor for A is declared and not declared for B, get a:
    //WARNING: B: destructor was implicitly defined as deleted? C4624
	//ERROR:   B:~B cannot override A:~A
	// The above errors are gone when virtual ~A() is declared public
};
int main_VirtualFunction()
{
	A *a = new A;
	B *b = new B;
	A *ab;
	B *ba;

	a->printMe();
	b->printMe(); // virtual function not required. Child object calls child's method

	ab = b;  // can assign a parent pointer to a child pointer;
	ab->printMe(); // Because printMe() is not virtual, even if ab points to b, A's method is called.
	ab->singMe();  // Because singMe() is virtual, when a points to b, B's method is called.

	//ba = a; // Cannot assign a child pointer to a parent pointer
	delete a;
	//delete b; // if B does not override its destructor, delete b will invoke A's destructor
	delete ab; // if a and b are deleted before ab, an exception is thrown. Because ab was assigned b and b is deleted, trying to 
	           // delete a deleted pointer raised an exception.
	           // However, if b is not deleted prior to ab, when delete ab is called, it goes to A's virtual destructor because b doesn't have 
	           // one overridden. This does not raise any exceptions, but what is likely happening is, the memory pointed to by ab (b) is 
	           // released. Trying to delete b after this raises an exception.
	           // However, according to the understanding we've had so far, it looks like if there was no destructor for b, the implementation 
			   // would execute A's destructor, leaving memory pointed to by b dangling. However, since we had a reference to the same memory 
	           // by b, it should have been released when I tried to release b later. Why do we get an exception when we try to delete b
			   // after ab, even when B does not have a destructor?
	//delete b;  // If ab is deleted before b, deleting b raises an exception.

	return 0;

}