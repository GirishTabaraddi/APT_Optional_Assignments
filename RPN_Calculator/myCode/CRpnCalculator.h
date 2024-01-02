/*!
 * @file CRpnCalculator.h
 *
 *  Created on: 02-Jan-2024
 *      Author: giris
 */

#ifndef CRPNCALCULATOR_H_
#define CRPNCALCULATOR_H_

#include "CLifoBuffer.h"

class CRpnCalculator
{
private:
	/*!
	 * @var m_stack : an object of CLifoBuffer as an private member of the class.
	 */
	CLifoBuffer m_stack;

public:
	/*!
	 * A parameterized constructor which initializes stack size.
	 * @param stackSize
	 */
	CRpnCalculator(int stackSize);

	/*!
	 * The pushValue() method delegate directly to the
	 * corresponding method of the stack attribute(the LIFO buffer).
	 * @param data
	 * @return boolean value
	 */
	bool pushValue(const CFraction& data);

	/*!
	 * The popValue() method delegate directly to the
	 * corresponding method of the stack attribute(the LIFO buffer).
	 * @param data
	 * @return boolean value
	 */
	bool popResult(CFraction& data);

	/*!
	 * A void method to print the stack through m_stack variable.
	 */
	void printStack();

	/*!
	 * add() method to add a fraction+fraction / fraction+integer / integer+fraction.
	 */
	void add();

	/*!
	 * subtract() method to add a fraction-fraction / fraction-integer / integer-fraction.
	 */
	void subtract();

	/*!
	 * multiply() method to add a fraction*fraction / fraction*integer / integer*fraction.
	 */
	void multiply();

	/*!
	 * divide() method to add a fraction/fraction / fraction/integer / integer/fraction.
	 */
	void divide();
};

#endif /* CRPNCALCULATOR_H_ */
