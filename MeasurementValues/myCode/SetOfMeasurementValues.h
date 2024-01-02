/**
 * SetOfMeasurementValues.h
 *
 *  Created on: 26-Nov-2023
 *      Author: giris
 */
#include <string>

#ifndef SETOFMEASUREMENTVALUES_H_
#define SETOFMEASUREMENTVALUES_H_

#define MAXVALUE 10
#define NOVALUE -9999

typedef enum
{
	A,
	V,
	S,
	W,
	NONE
}t_unit;

/**
 * Develop a class which stores a set of measurement values.
 * Declare the class based on the UML diagram in the file SetOfMeasurementValues.h
 */
class SetOfMeasurementValues
{
private:
	double m_value[10];
	t_unit m_unit;
	std::string m_name;

public:
	/**
	 * Implement the constructor in the file SetOfMeasurementValues.cpp.
	 * All values of the array are initialized with NOVALUE.
	 * Set name and unit to the given parameters.
	 * Provide sensible default values for all parameters of the constructor.
	 * Print the address of the object using the this Pointer.
	 * @param name
	 * @param unit
	 */
	SetOfMeasurementValues(std::string name, t_unit unit);

	/**
	 * Implement the method setValue, setting value at the given position to the corresponding parameter value.
	 * The values of the unit and name attributes are not changed.
	 * In case the parameter pos is out of the range of the array, an error message shall be printed and no value may be changed.
	 * @param pos
	 * @param value
	 */
	void setValues(unsigned int pos, double value);

	/**
	 * Implement the method setRandomValues().
	 * This method sets all values of the array to a value between min and max,having 1 decimal digit accuracy.
	 * Hint: Use the function rand() of the standard libraries and seed it with the current time value.
	 * @param min
	 * @param max
	 */
	void setRandomValues(int min, int max);

	/**
	 * Implement the method print(), which prints all valid values and the min, max and average value of the array.
	 * Hint: Do not copy any code, use the already implemented methods instead.
	 */
	void print();

	/**
	 * Implement the method getValue(). In case the position parameter is out of range,
	 * an error message shall be printed and the value NOVALUE is returned.
	 * @param pos
	 * @return double
	 */
	double getValue(unsigned int pos);

	/**
	 * Implement the method getAverage following the same logic like the previous methods getMin() & getMax(),
	 * i.e. the average value of all valid values is calculated.
	 * @return double
	 */
	double getAverage();

	/**
	 * Implement the method getMax(). This function only considers valid measurement values,
	 * i.e. values not having the value NOVALUE. The minimum value is returned.
	 * In case no valid value is contained in the array, the value NOVALUE shall be returned.
	 * @return double
	 */
	double getMax();

	/**
	 * Implement the method getMin(). This function only considers valid measurement values,
	 * i.e. values not having the value NOVALUE. The minimum value is returned.
	 * In case no valid value is contained in the array, the value NOVALUE shall be returned.
	 * @return double
	 */
	double getMin();

private:
	/**
	 * Implement the method printSingleValue(), printing the value of value at the given
	 * position as well as the unit, using the following strings: Ampere, Volt, seconds, Watt.
	 * Hint:Use a switch statement for the units.
	 * @param pos
	 */
	void printSingleValue(unsigned int pos);

};

#endif /* SETOFMEASUREMENTVALUES_H_ */
