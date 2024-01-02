//! Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>

using namespace std;

//! Add your project's header files here
// #include "CFraction.h"
#include "Complex.h"

// Main program
int main ()
{
	cout << "Complex_Operator_Overloading started." << endl << endl;

	/**
	 * Test the constructor by defining the following objects and printing them:
	 */
	cout << "Some Objects" << endl << "============" << endl;

	Complex c1;

	Complex c2(1,3);

	Complex c3(4);

	Complex c4(c3);

	cout << "Some Calculations" << endl << "=================" << endl;
//
	c1 = c2 + c3; //!< complex + complex operation
	cout << "c1: " << c1 << endl;
//
//	c2 = c3 * c2; //!< complex * complex operation
//	cout << "c2: " << c2 << endl;
//
//	c3 = c3 - c2; //!< complex - complex operation
//	cout << "c3: " << c3 << endl;
//
//	c4 = c2 / c1; //!< complex / complex operation
//	cout << "c4: " << c4 << endl;

//	Complex c5(4);
	float x = 3.14;
	c1 = c3 + x; //!< float + complex operation
	cout << "c1: " << c1 << endl;

	c2 = c2 * 4; //!< float * complex operation
	cout << "c2: " << c2 << endl;

	c2 = c2 * x; //!< float * complex operation
	cout << "c2: " << c2 << endl;

	cout << "Post and Pre-Increment" << endl << "======================" << endl;

	Complex a;
	Complex b;

	b = ++a;
	cout << "++a = " << a << "; b=++a = " << b << endl;

	b.set(0,0);
	b = a++;
	cout << "a++ = " << a << "; b=a++ = " << b << endl;


	return 0;
}
