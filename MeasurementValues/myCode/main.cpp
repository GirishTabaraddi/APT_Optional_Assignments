//! Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>

using namespace std;

//! Add your project's header files here
// #include "CFraction.h"
#include "SetOfMeasurementValues.h"

//! Main program
int main ()
{
	cout << "MeasurementValues started." << endl;

	/**
	 * Test the class by creating an object myVoltageValues in main.cpp,
	 * having the name "myVoltageValues” and the unit V.
	 */
	cout << endl << "Testing a first object....." << endl;

	SetOfMeasurementValues obj1("myVoltageValues", V);

	/**
	 * Test the code by setting element 1 to the value 10 and element 3 of myVoltageValues to 20.
	 * Print the object myVoltageValues.
	 */
	obj1.setValues(1, 10);
	obj1.setValues(3, 20);

	obj1.print();

	/**
	 * Test the code by setting the value at position 30 to 20 and try to read the value from pos 77.
	 */
	cout << endl << "Testing some exceptions....." << endl;
	obj1.setValues(30, 20);
	obj1.getValue(77);

	/**
	 * Create a second object myCurrentValues (Unit A, name “myCurrentValues”).
	 * Set all values to random value between 0 and 100.
	 */
	cout << endl << "Testing a second object....." << endl;

	SetOfMeasurementValues obj2("myCurrentValues", A);
	obj2.setRandomValues(0, 100);
	obj2.print();

	return 0;
}
