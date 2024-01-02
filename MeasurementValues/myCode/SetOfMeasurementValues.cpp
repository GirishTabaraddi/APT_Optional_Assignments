/**
 * SetOfMeasurementValues.cpp
 *
 *  Created on: 26-Nov-2023
 *      Author: giris
 */
#include <iostream>
#include <stdlib.h>

#include "SetOfMeasurementValues.h"

using namespace std;

SetOfMeasurementValues::SetOfMeasurementValues(std::string name, t_unit unit)
{
	this->m_unit = unit;
	this->m_name = name;

	for(int i = 0; i < MAXVALUE; i++)
	{
		this->m_value[i] = NOVALUE;
	}

	cout << "Created object at : " << this << endl;
}

void SetOfMeasurementValues::setValues(unsigned int pos, double value)
{
	if(pos < 0 || pos > 10)
	{
		cout << "ERROR setValue: Position out of bounds" << endl;
	}
	else
	{
		this->m_value[pos] = value;
	}
}

double SetOfMeasurementValues::getValue(unsigned int pos)
{
	if(pos < 0 || pos > 10)
	{
		cout << "ERROR getValue: Position out of bounds" << endl;
		cout << "Returning a value: " << NOVALUE << endl;
		return NOVALUE;
	}
	else
	{
		return this->m_value[pos];
	}
}

void SetOfMeasurementValues::print()
{
	cout << this->m_name <<":" << endl;

	for(int i = 0; i < 10; i++)
	{
		if(this->m_value[i] != NOVALUE)
		{
			printSingleValue(i);
		}
	}

	cout << "  Max Value: " << getMax() << endl;
	cout << "  Min Value: " << getMin() << endl;
	cout << "  Avg Value: " << getAverage() << endl;
}

double SetOfMeasurementValues::getMin()
{
    size_t m_value_size = sizeof(this->m_value) / sizeof(this->m_value[0]);

    double min = this->m_value[0];

    bool validValueFlag = false;

    for (size_t i = 0; i < m_value_size; i++)
    {
        if (this->m_value[i] != NOVALUE)
        {
            double x = this->m_value[i];
            validValueFlag = true;

            if (min == NOVALUE || x < min)
            {
                min = x;
            }
        }
    }

    return (validValueFlag) ? min : NOVALUE;
}

double SetOfMeasurementValues::getMax()
{
	size_t m_value_size = sizeof(this->m_value)/sizeof(this->m_value[0]);

	double max = this->m_value[0];

	bool validValueFlag = false;

	for(size_t i = 0; i < m_value_size; i++)
	{
		if(this->m_value[i] != NOVALUE)
		{
			validValueFlag = true;

			if(max < this->m_value[i])
			{
				max = this->m_value[i];
			}
		}
	}
	return (validValueFlag) ? max : NOVALUE;
}

double SetOfMeasurementValues::getAverage()
{
	size_t m_value_size = sizeof(this->m_value)/sizeof(this->m_value[0]);

	double sum = 0;

	int validCount = 0;

	for(size_t i = 0; i < m_value_size; i++)
	{
		if(this->m_value[i] != NOVALUE)
		{
			validCount++;

			sum += this->m_value[i];
		}
	}

	return (validCount > 0) ? sum/validCount : NOVALUE;
}

void SetOfMeasurementValues::setRandomValues(int min, int max)
{
	srand((unsigned) time(NULL));

	for(int i = 0; i < 10; i++)
	{
		int randomInt = min + (rand() % (max-min+1));

		int random_decimal = rand() % 10;

		float random = (float)randomInt + (float)random_decimal/10.0;

		setValues(i, random);
	}
}

void SetOfMeasurementValues::printSingleValue(unsigned int pos)
{
	switch(this->m_unit)
	{
	case A:
	{
		cout << "  Value[" << pos << "]: " << getValue(pos) << " Ampere" << endl;
		break;
	}
	case V:
	{
		cout << "  Value[" << pos << "]: " << getValue(pos) << " Volt" << endl;
		break;
	}
	case S:
	{
		cout << "  Value[" << pos << "]: " << getValue(pos) << " seconds" << endl;
		break;
	}
	case W:
	{
		cout << "  Value[" << pos << "]: " << getValue(pos) << " Watt" << endl;
		break;
	}
	case NONE:
	{
		cout << "  NONE" << endl;
		break;
	}
	default:
		break;
	}
}
