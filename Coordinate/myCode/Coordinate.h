/*
 * Coordinate.h
 *
 *  Created on: 09-Nov-2023
 *      Author: giris
 */

#ifndef COORDINATE_H_
#define COORDINATE_H_

typedef enum
{
	CARTESIAN	= 	0,
	CYLINDER	=	1,
	POLAR		=	2
}t_coordinate;

class Coordinate
{
	float m_x;
	float m_y;
	float m_z;
public:
	//Coordinate();
	Coordinate(float x = 0, float y = 0, float z = 0);
	virtual ~Coordinate();

	void setCartesian(float x, float y, float z);
	void getCartesian(float& x, float& y, float& z);
	void add(const Coordinate &C);
	void print(t_coordinate style);
	void getPolar(float& r, float& phi, float& theta);
	void getCylinder(float& r, float& phi, float& h);
};

#endif /* COORDINATE_H_ */
