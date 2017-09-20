#include <iostream>
#include "StaticConcepts.h"

namespace staticConcepts
{
	// 1. Static member variables
	// 2. Static member functions: can only modify static variables, can modify static private variables

	class StaticDataAndMethod {
	public:
		//static struct Vertex {
		//	int pos;
		//	int col;
		//}v;
		//// What about pointers?
		//static int* p;
		/*static void setColor(int argColor)
		{
			color = argColor;
		}*/
		//int getColor()
		//{
		//	return color;
		//}

		int getPosition()  
			// Can be accessed by instances of the class. 
		{
			return position;
		}

		void setPosition(int argPos)
		{
			position = argPos;
		}

		static int color; // Color needs to be seen the same from all instances of the class. Then, this can be accessed
		//// from the class itself and we don't need methods to access this. In case this is a static private variable,
		//// we will have a function provide access to this variable. Qn: Does this function have to be static?
		// Cannot have a public static variable?

	private:
		int position;
		//static int color;  // private members cannot be accessed from class, even if static


	};
	// 3. Static class
	// 4. static local variables (accessible within the function, persists across function calls) 
		// global variables (accessible within all functions in the translation unit, persists across function calls)
	// 5. static function variables
	// 6. Implementing singleton class using static class?
};

int staticConcepts::StaticDataAndMethod::color = 0x000000FF;
using namespace staticConcepts;
using namespace std;
int main_StaticConcepts()
{
	//StaticDataAndMethod::color = 0x000000FF; // RED: 'Syntax error: missing ';' before '.' Why doesn't this work? Shouldn't I be able to 
	// access a public static member variable by the class?
	cout << "Color is: " << StaticDataAndMethod::color << endl;

	StaticDataAndMethod *sdm = new StaticDataAndMethod(); // Don't get any errors for anything in the class until I start using the 
	// object for any function. Looks like all the functions and variables are resolved only when there is use of the object.
	cout << "Let's set color again" << endl;
	StaticDataAndMethod::color = 0x0000FF00;
	cout << "Color is: " << StaticDataAndMethod::color << endl;
	//StaticDataAndMethod.setColor(0x000000FF); // 'Syntax error: missing ';' before '.' This is a COMPILE ERROR. You cannot access functions,
	// even static functions directly from the class. Has to be accessed by an object.
	//sdm->setColor(0x000000FF); 
	sdm->setPosition(0);

	//cout << "New color is: " << sdm->getColor() << endl; // Need to read color variable through a non-static method. But this is wrong since 
	// color is a static variable, should be accessed via a static method only, which can be accessed by the class.

	return 0;
}