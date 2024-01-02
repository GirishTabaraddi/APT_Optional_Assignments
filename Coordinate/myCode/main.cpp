// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>
#include "Coordinate.h"

using namespace std;

// Add your project's header files here
// #include "CFraction.h"

// Main program
int main ()
{
	cout << "Coordinate started." << endl << endl;

	// Create a object of class Coordinate
	Coordinate c1(4, 4, 2);
	Coordinate c2;
	Coordinate c3 (-4);

	//Test the print operation
	cout << "================Printing================" << endl;
	c1.print(CARTESIAN);
	c1.print(CYLINDER);
	c2.print(CYLINDER);

	c1.print(POLAR);
	c2.print(POLAR);
	c3.print(POLAR);

	//Test the add operation
	cout << "================Adding================" << endl;
	c1.add(c3);
	c2.add(Coordinate(10, 20, 30));
	c1.print(CARTESIAN);
	c2.print(CARTESIAN);

	return 0;
}
