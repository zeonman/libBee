/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#ifndef BEE_DATA_STRUCTURE_QUEUE_H_
#define BEE_DATA_STRUCTURE_QUEUE_H_

#include "NodeQueue.h"
#include "node.h"
#include "ArrayQueue.h"

namespace Bee
{

template<typename ELEMENT_T, int BLOCK_SIZE = 50>
class Queue
{
	static_assert(BLOCK_SIZE > 0, "BLOCK_SIZE <= 0");

public:
	inline Queue();

	inline bool is_empty() const noexcept;
	inline ELEMENT_T* front() noexcept; // Return nullptr on empty
	inline ELEMENT_T const* front() const noexcept; // Return nullptr on empty

	int __fastcall enqueue(ELEMENT_T const &element) noexcept; // Return 0 on success, or -1 when memory alloc fail
	void dequeue() noexcept;

protected:
	class Block : public ArrayQueue<ELEMENT_T, BLOCK_SIZE>, public DoublyNode
	{
	};
	NodeQueue m_queue_block;
};

} // namespace Bee

#include "Queue.inl"

#endif // BEE_DATA_STRUCTURE_QUEUE_H_