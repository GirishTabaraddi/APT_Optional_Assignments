/*!
 * @file CLifoBuffer.h
 *
 *  Created on: 01-Jan-2024
 *      Author: giris
 */

#ifndef CLIFOBUFFER_H_
#define CLIFOBUFFER_H_

#include <iostream>

//! Copy the existing class Fraction to the new project.
#include "CFraction.h"

class CLifoBuffer
{
private:
	/*!
	 * @var m_size : int, size of Lifo Buffer.
	 */
	int m_size;
	/*!
	 * @var m_tos : int, pointer the top of stack, defaults to -1.
	 */
	int m_tos;
	/*!
	 * @var m_pBuffer : CFraction*, pointer object to CFraction class.
	 */
	CFraction* m_pBuffer;

public:
	/*!
	 * The constructor. Allocate the required memory.
	 * Set the pointer to the top of stack (tos) to -1.
	 * Using this invalid index indicates that the stack is empty.
	 * @param size
	 */
	CLifoBuffer(int size);

	/*!
	 * A destructor for LifoBuffer class.
	 * Make sure that all allocated memory is released.
	 */
	virtual ~CLifoBuffer();

	/*!
	 * The print() operation, printing the values of all attributes
	 * as well as the content of the buffer.
	 */
	void print();

	/*!
	 * The push() operation. Check if there is still memory left.
	 * In case there is, increment the top of stack pointer and store the value.
	 * @param data
	 * @return boolean value
	 */
	bool push(const CFraction& data);

	/*!
	 * The pop() operation. Check if there is a value in the buffer.
	 * In case there is, return it and decrement the top of stack.
	 * @param data
	 * @return boolean value
	 */
	bool pop(CFraction& data);
};

#endif /* CLIFOBUFFER_H_ */
