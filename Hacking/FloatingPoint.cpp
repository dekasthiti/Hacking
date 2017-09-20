#include <limits>
#include <iostream>
#include "FloatingPoint.h"

int main_floatingPoint()
{
	double a = 1.0;
	double b = 1.1;
	//std::cout << nextafter(a, b) << std::endl;
	std::cout << "Double Epsilon (decimal): " << DBL_EPSILON << std::endl;
	std::cout << "Double Epsilon (hex): " << std::hex << DBL_EPSILON << std::endl;
	std::cout << "Double Epsilon (hexfloat): " << std::hexfloat << DBL_EPSILON << std::endl;
	//std::cout << "Infinity: " << std::dec << INFINITY << std::endl;
	//std::cout << "NaN: " << std::hexfloat << INFINITY * 0.0f << std::endl;
	std::cout << "Denorm error mask " << std::hexfloat << _EM_DENORMAL << std::endl;
	std::cout << "Denorm " << std::hexfloat << FLT_TRUE_MIN << std::endl;
	std::cout << "Denorm " << std::hexfloat << DBL_TRUE_MIN << std::endl;
	return 0;

}
