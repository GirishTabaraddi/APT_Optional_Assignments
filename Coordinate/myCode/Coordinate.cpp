/*
 * Coordinate.cpp
 *
 *  Created on: 09-Nov-2023
 *      Author: giris
 */
#include <iostream>
#include <math.h>

#include "Coordinate.h"

#define PI_radians 3.14
#define PI_degrees 180
#define degree_to_radians (PI_degrees/PI_radians)
using namespace std;

Coordinate::Coordinate(float x, float y, float z)
{
	this->m_x = x;
	this->m_y = y;
	this->m_z = z;

	cout << "Constructor generates object at " << this << endl;
	cout << "Value = (" << this->m_x << "," << this->m_y << "," << this->m_z << ")" << endl;
}

Coordinate::~Coordinate()
{
	cout << "Destructor destroys object at " << this << endl;
}

void Coordinate::setCartesian(float x, float y, float z)
{
	this->m_x	=	x;
	this->m_y	=	y;
	this->m_z	=	z;
}

void Coordinate::getCartesian(float &x, float &y, float &z)
{
	x = m_x;
	y = m_y;
	z = m_z;
}

void Coordinate::add(const Coordinate &C)
{
	m_x += C.m_x;
	m_y += C.m_y;
	m_z += C.m_z;
}

void Coordinate::print(t_coordinate style)
{
	switch(style)
	{
		case CARTESIAN:
		{
			cout << "Cartesian Representation (x,y,z) = (" << m_x << "," << m_y << "," << m_z << ")" << endl;
			break;
		}
		case CYLINDER:
		{
			float cyl_x, cyl_y, cyl_z;
			getCylinder(cyl_x, cyl_y, cyl_z);

			cout << "Cylinder Representation (r, phi, z) = (" << cyl_x << "," << cyl_y << "," << cyl_z << ")" << endl;
			break;
		}
		case POLAR:
		{
			float p_x, p_y, p_z;
			getPolar(p_x, p_y, p_z);

			cout << "Polar Representation (r, phi, theta) = (" << p_x << "," << p_y << "," << p_z << ")" << endl;
			break;
		}
		default:
			cout << "error in types of coordinates!!!" << endl;
			break;

	}
}

void Coordinate::getPolar(float &r, float &phi, float &theta)
{
	r = sqrt((this->m_x * this->m_x) + (this->m_y * this->m_y) + (this->m_z * this->m_z));

	phi = atan2(this->m_y, this->m_x) * degree_to_radians;

	theta = PI_degrees/2 - (atan(this->m_z/(sqrt(this->m_x*this->m_x + this->m_y*this->m_y))) * degree_to_radians);
}

void Coordinate::getCylinder(float &r, float &phi, float &h)
{
	r = sqrt(this->m_x * this->m_x + this->m_y * this->m_y);

	if(this->m_x > 0)
	{
		phi = (atan(this->m_y/this->m_x) * degree_to_radians);
	}
	if(this->m_x < 0 && this->m_y >= 0)
	{
		phi = (atan(this->m_y/this->m_x) * degree_to_radians)+ PI_degrees;
	}
	if(this->m_x < 0 && this->m_y < 0)
	{
		phi = (atan(this->m_y/this->m_x) * degree_to_radians)- PI_degrees;
	}
	if(this->m_x == 0 && this->m_y > 0)
	{
		phi = PI_degrees/2;
	}
	if(this->m_x == 0 && this->m_y == 0)
	{
		phi = 0;
	}

	h = this->m_z;
}
