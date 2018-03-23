/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#ifndef BEE_DATA_STRUCTURE_ARRAY_QUEUE_H_
#define BEE_DATA_STRUCTURE_ARRAY_QUEUE_H_

namespace Bee
{

template<typename ELEMENT_T, int ARRAY_SIZE = 10>
class ArrayQueue
{
	static_assert(ARRAY_SIZE > 0, "ARRAY_SIZE <= 0");

public:
	inline ArrayQueue() noexcept = default;

	inline bool is_empty() const noexcept;
	ELEMENT_T* front() noexcept; // Return nullptr on empty
	ELEMENT_T const* front() const noexcept; // Return nullptr on empty

	int __fastcall enqueue(ELEMENT_T const &element) noexcept; // Return 0 on success, or -1 on full
	void dequeue() noexcept;

protected:
	ELEMENT_T m_elements[ARRAY_SIZE];
	int m_front = 0;
	int m_rear = 0; // The highest bit is full flag
	enum {
		STATE_FLAG_FULL = ~((unsigned int)-1 >> 1)
	};
};

} // namespace Bee

#include "ArrayQueue.inl"

#endif // BEE_DATA_STRUCTURE_ARRAY_QUEUE_H_