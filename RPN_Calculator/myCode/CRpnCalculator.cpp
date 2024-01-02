/*!
 * @file CRpnCalculator.cpp
 *
 *  Created on: 02-Jan-2024
 *      Author: giris
 */

#include "CRpnCalculator.h"

using namespace std;

CRpnCalculator::CRpnCalculator(int stackSize) : m_stack(stackSize)
{
}

bool CRpnCalculator::pushValue(const CFraction &data)
{
	return this->m_stack.push(data);
}

bool CRpnCalculator::popResult(CFraction &data)
{
	return this->m_stack.pop(data);
}

void CRpnCalculator::printStack()
{
	this->m_stack.print();
}

void CRpnCalculator::add()
{
	CFraction value1, value2;

	if(this->m_stack.pop(value1) && this->m_stack.pop(value2))
	{
		this->m_stack.push(value1 + value2);
	}
	else
	{
		cout << "Not enough elements on the stack to perform add() !!!" << endl;
	}
}

void CRpnCalculator::subtract()
{
	CFraction value1, value2;

	if(this->m_stack.pop(value1) && this->m_stack.pop(value2))
	{
		this->m_stack.push(value2 - value1);
	}
	else
	{
		cout << "Not enough elements on the stack to perform subtract() !!!" << endl;
	}
}

void CRpnCalculator::multiply()
{
	CFraction value1, value2;

	if(this->m_stack.pop(value1) && this->m_stack.pop(value2))
	{
		this->m_stack.push(value1 * value2);
	}
	else
	{
		cout << "Not enough elements on the stack to perform multiply() !!!" << endl;
	}
}

void CRpnCalculator::divide()
{
	CFraction value1, value2;

	if(this->m_stack.pop(value1) && this->m_stack.pop(value2))
	{
		this->m_stack.push(value2 / value1);
	}
	else
	{
		cout << "Not enough elements on the stack to perform divide() !!!" << endl;
	}
}
