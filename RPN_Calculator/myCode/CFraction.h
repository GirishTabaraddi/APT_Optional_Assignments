/*!
 * CFraction.h
 *
 *  Created on: 28-Dec-2023
 *      Author: giris
 */

#ifndef CFRACTION_H_
#define CFRACTION_H_

#include <iostream>

/*!
 * CFraction is a class which stores fractions using the format f = n/d
 * and supports the binary operations+, -, *, /
 * as well as the unary operations c++ and ++c.
 */
class CFraction
{
private:
	long m_numerator;
	long m_denominator;

private:
	/*!
	 * This method calculates the gcd of num and den,
	 * then normalizes the fraction. If it is 98/56, then gcd is 14
	 * so the new fraction will be 7/4.
	 */
	void shorten();

public:
	/*!
	 * A parameterized constructor that takes num = 0, den = 1 as default values.
	 * If numerator < 0 and denominator < 1, then the default values 0 and 1 are set.
	 * @param numerator
	 * @param denominator
	 */
	CFraction(long numerator = 0, long denominator = 1);

	virtual ~CFraction();

	/*!
	 * A void set method sets the provided num and den from the arguments,
	 * if num < 0 and den < 1, then an error message is displayed.
	 * @param numerator
	 * @param denominator
	 */
	void set(long numerator, long denominator);

	/*!
	 * The toDouble() method in the context of a CFraction class would be a method
	 * that calculates and returns the decimal (floating-point) representation of the fraction.
	 * In other words, it converts the fraction into a floating-point number.
	 * @return double value
	 */
	double toDouble();

	/*!
	 * A void print method to display the num and den in the format:
	 * Fraction [numerator = value; denominator = value]
	 */
	void print();

	/*!
	 * The overloaded << Operator, which prints the fraction as
	 * “(numerator/denominator)” (without trailing newline).
	 * @param out
	 * @param CFractionObj
	 * @return
	 */
	friend std::ostream& operator<<(std::ostream& out, const CFraction& CFractionObj);

	/*!
	 * A pre-increment method
	 * @return
	 */
	CFraction& operator++();

	/*!
	 * A post-increment method
	 * @param
	 * @return
	 */
	CFraction operator++(int);

	/*!
	 * + overloaded operator method, supporting operations between fraction + fraction.
	 * @param fObj
	 * @return CFraction
	 */
	CFraction operator+(const CFraction& fObj) const;

	/*!
	 * + overloaded operator method, supporting operations between fraction + integer.
	 * @param fObj
	 * @return CFraction
	 */
	CFraction operator+(int OtherInteger) const;

	/*!
	 * + overloaded operator method, supporting operations between integer + fraction.
	 * @param OtherInteger
	 * @param fObj
	 * @return
	 */
	friend CFraction operator+(int OtherInteger, const CFraction& fObj);

	/*!
	 * + overloaded operator method, supporting operations between fraction * fraction.
	 * @param fObj
	 * @return CFraction
	 */
	CFraction operator*(const CFraction& fObj) const;

	/*!
	 * + overloaded operator method, supporting operations between fraction * integer.
	 * @param fObj
	 * @return CFraction
	 */
	CFraction operator*(int OtherInteger) const;

	/*!
	 * + overloaded operator method, supporting operations between integer * fraction.
	 * @param OtherInteger
	 * @param fObj
	 * @return
	 */
	friend CFraction operator*(int OtherInteger, const CFraction& fObj);

	/*!
	 * + overloaded operator method, supporting operations between fraction / fraction.
	 * @param fObj
	 * @return CFraction
	 */
	CFraction operator/(const CFraction& fObj) const;

	/*!
	 * + overloaded operator method, supporting operations between fraction / integer.
	 * @param fObj
	 * @return CFraction
	 */
	CFraction operator/(int OtherInteger) const;

	/*!
	 * + overloaded operator method, supporting operations between integer / fraction.
	 * @param OtherInteger
	 * @param fObj
	 * @return
	 */
	friend CFraction operator/(int OtherInteger, const CFraction& fObj);

	/*!
	 * + overloaded operator method, supporting operations between fraction - fraction.
	 * @param fObj
	 * @return CFraction
	 */
	CFraction operator-(const CFraction& fObj) const;

	/*!
	 * + overloaded operator method, supporting operations between fraction - integer.
	 * @param fObj
	 * @return CFraction
	 */
	CFraction operator-(int OtherInteger) const;

	/*!
	 * + overloaded operator method, supporting operations between integer - fraction.
	 * @param OtherInteger
	 * @param fObj
	 * @return
	 */
	friend CFraction operator-(int OtherInteger, const CFraction& fObj);
};

#endif /* CFRACTION_H_ */
