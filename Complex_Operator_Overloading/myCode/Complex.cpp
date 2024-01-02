/**
 * Complex.cpp
 *
 *  Created on: 26-Nov-2023
 *      Author: giris
 */

#include <math.h>

#include "Complex.h"

using namespace std;

Complex::Complex(float real, float imaginary)
{
	if( (-100 < real && real < 100) && (-100 < imaginary && imaginary < 100))
	{
		this->m_real = real;
		this->m_imaginary = imaginary;
	}
	else
	{
		this->m_real = 0;
		this->m_imaginary = 0;
	}

	cout << "Complex object generated at " << this << endl;
	print();
}

Complex::Complex(const Complex &other)
{
	this->m_real = other.m_real;
	this->m_imaginary = other.m_imaginary;

}

void Complex::set(float real, float imaginary)
{
	if( (-100 < real && real < 100) && (-100 < imaginary && imaginary < 100))
	{
		this->m_real = real;
		this->m_imaginary = imaginary;
	}
	else
	{
		cout << "ERROR SetValues: Out of boundary values for real and Imaginary!!" << endl;
	}
}

float Complex::abs()
{
	float abs_value = sqrtf((this->m_real*this->m_real) + (this->m_imaginary*this->m_imaginary));

	return abs_value;
}

void Complex::print()
{
	cout << "Value = " << this->m_real << " + i" << this->m_imaginary << endl;
}

ostream& operator<<(ostream& out, Complex& c)
{
	if(c.m_imaginary > 0)
	{
		out << "" << c.m_real << " + i" << c.m_imaginary;
	}
	else if(c.m_imaginary < 0)
	{
		out << "" << c.m_real << " - i" << c.m_imaginary;
	}
	else if(c.m_imaginary == 0)
	{
		out << "" << c.m_real;
	}

	return out;
}

Complex& Complex::operator ++()
{
	this->m_real += 1;
	this->m_imaginary += 1;
	return *this;
}

Complex Complex::operator ++(int)
{
	Complex temp = *this;
	this->m_real += 1;
	this->m_imaginary += 1;
	return temp;
}

Complex Complex::operator +(const Complex &rhsObj) const
{
	Complex res;

	res.m_real = this->m_real + rhsObj.m_real;
	res.m_imaginary = this->m_imaginary + rhsObj.m_imaginary;

	return res;
}

Complex Complex::operator -(const Complex &rhsObj)
{
	Complex res;

	res.m_real = this->m_real - rhsObj.m_real;
	res.m_imaginary = this->m_imaginary - rhsObj.m_imaginary;

	return res;
}

Complex Complex::operator *(const Complex &rhsObj)
{
	Complex res;

	res.m_real = this->m_real * rhsObj.m_real;
	res.m_imaginary = this->m_imaginary * rhsObj.m_imaginary;

	return res;
}

Complex Complex::operator /(const Complex &rhsObj)
{
	Complex res;

	res.m_real = this->m_real / rhsObj.m_real;
	res.m_imaginary = this->m_imaginary / rhsObj.m_imaginary;

	return res;
}

Complex Complex::operator +(float other) const
{
	Complex res;

	res.m_real = this->m_real + other;
	res.m_imaginary = this->m_imaginary;

	return res;

//	return Complex(this->m_real+other, this->m_imaginary);
}

Complex operator +(float other, Complex &rhsObj )
{
	return Complex(rhsObj.m_real+other, rhsObj.m_imaginary);
}

Complex Complex::operator *(float other)
{
	return Complex(this->m_real*other, this->m_imaginary*other);
}

Complex operator *(float other, const Complex &rhsObj )
{
	return Complex(rhsObj.m_real*other, rhsObj.m_imaginary*other);
}
