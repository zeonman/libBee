/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#include <new>

namespace Bee
{

template<typename ELEMENT_T, int BLOCK_SIZE>
Queue<ELEMENT_T, BLOCK_SIZE>::Queue()
{
	Block *p_block = new Block;
	m_queue_block.enqueue(p_block);
}

template<typename ELEMENT_T, int BLOCK_SIZE>
bool
Queue<ELEMENT_T, BLOCK_SIZE>::is_empty() const noexcept
{
	return ((Block const*)m_queue_block.front())->is_empty();
}

template<typename ELEMENT_T, int BLOCK_SIZE>
ELEMENT_T*
Queue<ELEMENT_T, BLOCK_SIZE>::front() noexcept
{
	return ((Block*)m_queue_block.front())->front();
}

template<typename ELEMENT_T, int BLOCK_SIZE>
ELEMENT_T const*
Queue<ELEMENT_T, BLOCK_SIZE>::front() const noexcept
{
	return ((Block*)m_queue_block.front())->front();
}

template<typename ELEMENT_T, int BLOCK_SIZE>
int __fastcall
Queue<ELEMENT_T, BLOCK_SIZE>::enqueue(ELEMENT_T const &element) noexcept
{
	Block *p_block = (Block*)m_queue_block.rear();
	if (-1 == p_block->enqueue(element)) {
		p_block = new (std::nothrow) Block;
		if (!p_block)
			return -1;
		m_queue_block.enqueue(p_block);
		p_block->enqueue(element);
	}
	return 0;
}

template<typename ELEMENT_T, int BLOCK_SIZE>
void
Queue<ELEMENT_T, BLOCK_SIZE>::dequeue() noexcept
{
	Block *p_block_front = (Block*)m_queue_block.front();
	p_block_front->dequeue();
	if (p_block_front->is_empty() && p_block_front != m_queue_block.rear())
		delete (Block*)m_queue_block.dequeue();
}

} // namespace Bee