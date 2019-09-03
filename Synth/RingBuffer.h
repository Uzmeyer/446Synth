/*
 * RingBuffer.h
 *
 *  Created on: 26.04.2019
 *      Author: Jakob
 */

#ifndef SRC_RINGBUFFER_H_
#define SRC_RINGBUFFER_H_
#ifdef STM32
#include "stm32f4xx_hal.h"
#ednif
#define MIDIBUFFERSIZE 32

template <typename T, int size>
class RingBuffer {
public:
	RingBuffer()
	{
		clear();
	}

	virtual ~RingBuffer()
	{

	}

	void push(T element)
	{
		this->buffer[this->head] = element;
		this->head++;
		if(this->head >= size)
		{
			this->head = 0;
		}
		this->count++;
	}

	T pop()
	{
		T element = this->buffer[this->tail];
		if(this->tail >= size)
		{
			this->tail = 0;
		}
		this->count--;
		return element;
	}

	T peek()
	{
		return this->buffer[this->tail];
	}

	void clear()
	{
		this->head = 0;
		this->tail = 0;
		this->count = 0;
	}

	int getCount()
	{
		return this->count;
	}

	int calcCount()
	{
		int count = this->head - this->tail;
		if(this->tail > this->head)
		{
			count += size;
		}
		this->count = count;
		return this->count;
	}

	uint8_t checkFull()
	{
		return (this->head + 1 == this->tail) || (this->head == (size-1) && this->tail == 0);
	}

	uint8_t isFull()
	{
		return this->count >= size;
	}

	uint8_t isEmpty()
	{
		return this->tail == this->head;
	}

private:
	volatile int head;
	volatile int tail;
	volatile int count;
	T buffer[size+1];
};

#endif /* SRC_RINGBUFFER_H_ */
