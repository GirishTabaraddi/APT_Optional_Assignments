/*!
 * CFraction.cpp
 *
 *  Created on: 28-Dec-2023
 *      Author: giris
 */
#include "CFraction.h"

#include <cmath>

using namespace std;

CFraction::CFraction(long numerator, long denominator)
{
	if(denominator != 0)
	{
		if(denominator < 0)
		{
			numerator = -numerator;
			denominator = -denominator;
		}

		this->m_numerator = numerator;
		this->m_denominator = denominator;
	}
	else
	{
		this->m_numerator = 0;
		this->m_denominator = 1;
	}

	shorten();
}

CFraction::~CFraction()
{
}

void CFraction::set(long numerator, long denominator)
{
	if(denominator == 0)
	{
		cout << "Error: Denominator cannot be zero." << endl;
	}
	else
	{
		this->m_numerator = numerator;
		this->m_denominator = denominator;
	}
}

void CFraction::shorten()
{
	int gcd = min(this->m_numerator, this->m_denominator);

	while(gcd != 0)
	{
		if(this->m_numerator % abs(gcd) == 0 &&
				this->m_denominator % abs(gcd) == 0)
		{
			break;
		}
		gcd = (gcd > 0) ? gcd - 1 : gcd + 1;
	}

//	cout << "GCD: " << gcd << endl;

	if(gcd > 0)
	{
		this->m_numerator = this->m_numerator/gcd;
		this->m_denominator =  this->m_denominator/gcd;
	}
	else if(gcd < 0)
	{
		this->m_numerator = this->m_numerator/abs(gcd);
		this->m_denominator =  this->m_denominator/abs(gcd);
	}
	else
	{
		this->m_numerator = 0;
		this->m_denominator = 1;
	}
}

double CFraction::toDouble()
{
	return static_cast<double>(this->m_numerator)/this->m_denominator;
}

void CFraction::print()
{
	cout << "Fraction [numerator = " << this->m_numerator
			<< "; denominator = " << this->m_denominator << "]" << endl;
}

ostream& operator<<(std::ostream& out, const CFraction& CFractionObj)
{
	if(CFractionObj.m_denominator < 0)
	{
		out << "(" << -CFractionObj.m_numerator << "/" << -CFractionObj.m_denominator << ")";
	}
	else
	{
		out << "(" << CFractionObj.m_numerator << "/" << CFractionObj.m_denominator << ")";
	}

	return out;
}

CFraction& CFraction::operator ++()
{
	this->m_numerator = this->m_numerator + this->m_denominator;

	return *this;
}

CFraction CFraction::operator ++(int)
{
	CFraction temp = *this;

	this->m_numerator = this->m_numerator + this->m_denominator;

	return temp;
}

CFraction CFraction::operator +(const CFraction &fObj) const
{
	CFraction res;

	res.m_numerator = (this->m_numerator * fObj.m_denominator) +
						(this->m_denominator * fObj.m_numerator);
	res.m_denominator = this->m_denominator * fObj.m_denominator;

	res.shorten();

	return res;
}

CFraction CFraction::operator +(int OtherInteger) const
{
	CFraction res;

	res.m_numerator = (this->m_denominator * OtherInteger) + this->m_numerator;
	res.m_denominator = this->m_denominator;

	res.shorten();

	return res;
}

CFraction operator +(int OtherInteger, const CFraction &fObj)
{
	CFraction res;

	res.m_numerator = (fObj.m_denominator * OtherInteger) + fObj.m_numerator;
	res.m_denominator = fObj.m_denominator;

	res.shorten();

	return res;
}

CFraction CFraction::operator *(const CFraction &fObj) const
{
	CFraction res;

	res.m_numerator = (this->m_numerator * fObj.m_numerator);
	res.m_denominator = (this->m_denominator * fObj.m_denominator);

	res.shorten();

	return res;
}

CFraction CFraction::operator *(int OtherInteger) const
{
	CFraction res;

	res.m_numerator = this->m_numerator * OtherInteger;
	res.m_denominator = this->m_denominator;

	res.shorten();

	return res;
}

CFraction operator*(int OtherInteger, const CFraction& fObj)
{
	CFraction res;

	res.m_numerator = OtherInteger * fObj.m_numerator;
	res.m_denominator = fObj.m_denominator;

	res.shorten();

	return res;
}

CFraction CFraction::operator /(const CFraction &fObj) const
{
	CFraction res;

	res.m_numerator = (this->m_numerator * fObj.m_denominator);
	res.m_denominator = (this->m_denominator * fObj.m_numerator);

	res.shorten();

	return res;
}

CFraction CFraction::operator /(int OtherInteger) const
{
	CFraction res;

	res.m_numerator = this->m_numerator;
	res.m_denominator = this->m_denominator * OtherInteger;

	res.shorten();

	return res;
}

CFraction operator/(int OtherInteger, const CFraction& fObj)
{
	CFraction res;

	res.m_numerator = fObj.m_numerator;
	res.m_denominator = fObj.m_denominator * OtherInteger;

	res.shorten();

	return res;
}

CFraction CFraction::operator -(const CFraction &fObj) const
{
	CFraction res;

	res.m_numerator = (this->m_numerator*fObj.m_denominator - fObj.m_numerator*this->m_denominator);
	res.m_denominator = this->m_denominator*fObj.m_denominator;

	res.shorten();

	return res;
}

CFraction CFraction::operator -(int OtherInteger) const
{
	CFraction res;

	res.m_numerator = (this->m_numerator - OtherInteger*this->m_denominator);
	res.m_denominator = this->m_denominator;

	res.shorten();

	return res;
}

CFraction operator-(int OtherInteger, const CFraction& fObj)
{
	CFraction res;

	res.m_numerator = (OtherInteger*fObj.m_denominator - fObj.m_numerator);
	res.m_denominator = fObj.m_denominator;

	res.shorten();

	return res;
}
