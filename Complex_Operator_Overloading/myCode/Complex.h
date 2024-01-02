/**
 * Complex.h
 *
 *  Created on: 26-Nov-2023
 *      Author: giris
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>

/*!
 * Develop a class which stores complex numbers of the format c = a+bi
 * and supports the unary operations +,-,*,/ as well as the unary operations c++ and ++c.
 */
class Complex
{
private:
	float m_real;
	float m_imaginary;
public:
	/*!
	 * Implement the constructor, considering the given boundaries below.
	 * In case one of the values violates these boundaries, both values shall be set to 0
	 * -100 < real < 100 & -100 < imaginary < 100
	 * Print the address of the object as well as the attribute values on the screen.
	 * @param real
	 * @param imaginary
	 */
	Complex(float real = 0, float imaginary = 0);

	Complex(const Complex &other);

	/*!
	 * Implement the set function, considering the boundary values defined above.
	 * @param real
	 * @param imaginary
	 */
	void set(float real, float imaginary);

	/*!
	 * Implement the abs operation, which calculates the absolute value of the real number
	 * @return float value
	 */
	float abs();

	/*!
	 * Implement the print operation, which prints the complex number in the format real + i imaginary
	 */
	void print();

	/*!
	 * Implement the pre-increment operators, which add the value 1 to both the real and
	 * the imaginary part of the complex number.
	 * @return
	 */
	Complex& operator++();

	/*!
	 * Implement the post-increment operators, which add the value 1 to both the real and
	 * the imaginary part of the complex number.
	 * @return
	 */
	Complex operator++(int);

	/*!
	 * The overloaded << operator is for printing complex number.
	 * @param out - it is of ostream type.
	 * @param c - it is of complex type
	 * @return
	 */
	friend std::ostream& operator<<(std::ostream& out, Complex& c);

	/*!
	 * This unary + operator overloaded method is for complex + complex
	 * @param rhsObj
	 * @return
	 */
	Complex operator+(const Complex& rhsObj) const;

	/*!
	 * This unary - operator overloaded method is for complex - complex
	 * @param rhsObj
	 * @return
	 */
	Complex operator-(const Complex& rhsObj);

	/*!
	 * This unary * operator overloaded method is for complex * complex
	 * @param rhsObj
	 * @return
	 */
	Complex operator*(const Complex& rhsObj);

	/*!
	 * This unary / operator overloaded method is for complex / complex
	 * @param rhsObj
	 * @return
	 */
	Complex operator/(const Complex& rhsObj);

	/*!
	 * This unary + operator overloaded method is for float + complex
	 * @param other
	 * @return
	 */
	Complex operator+(float other) const;

	/*!
	 * This unary * operator overloaded method is for float * complex
	 * @param other
	 * @return
	 */
	Complex operator*(float other);

	friend Complex operator+(float other, Complex& rhsObj);

	friend Complex operator*(float other, const Complex& rhsObj);
};



#endif /* COMPLEX_H_ */
