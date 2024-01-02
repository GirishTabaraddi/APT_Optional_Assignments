/*!
 * @file CLifoBuffer.cpp
 *
 *  Created on: 01-Jan-2024
 *      Author: giris
 */

#include "CLifoBuffer.h"

using namespace std;

CLifoBuffer::CLifoBuffer(int size):m_size(size)
{
	this->m_tos = -1;

	this->m_pBuffer = new CFraction[size];

	for(int idx = 0; idx < size; idx++)
	{
		this->m_pBuffer[idx] = 0;
	}
}

CLifoBuffer::~CLifoBuffer()
{
	delete[] this->m_pBuffer;
}

void CLifoBuffer::print()
{
	cout << endl;

	cout << "value of m_size: " << this->m_size << endl;

	cout << "value of m_tos: " << this->m_tos << endl;

	if(this->m_tos == -1)
	{
		cout << "Buffer is empty!!!" << endl;
	}
	else
	{
		cout << "m_pBuffer content below: " << endl;

		for(int idx = 0; idx <= this->m_tos; idx++)
		{
			cout << "Buffer [" << idx << "] : " << this->m_pBuffer[idx] << endl;
		}
	}
	cout << endl;
}

bool CLifoBuffer::push(const CFraction &data)
{
	if(this->m_tos < this->m_size - 1)
	{
		this->m_pBuffer[++this->m_tos] = data;
		cout << "Pushed element: " << data << endl;

		return true;
	}
	else
	{
		cout << "No memory left to push!!" << endl;

		return false;
	}
}

bool CLifoBuffer::pop(CFraction &data)
{
	if(this->m_tos != -1)
	{
		data = this->m_pBuffer[this->m_tos--];

		return true;
	}
	else
	{
		cout << "No content left to pop from buffer!!" << endl;

		return false;
	}
}
