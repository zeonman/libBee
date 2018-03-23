/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#include <assert.h>

namespace Bee
{

template<typename ELEMENT_T, int ARRAY_SIZE>
bool
ArrayQueue<ELEMENT_T, ARRAY_SIZE>::is_empty() const noexcept
{
	return m_rear == m_front;
}

template<typename ELEMENT_T, int ARRAY_SIZE>
ELEMENT_T*
ArrayQueue<ELEMENT_T, ARRAY_SIZE>::front() noexcept
{
	if (m_rear == m_front)
		return nullptr;
	return m_elements + m_front;
}

template<typename ELEMENT_T, int ARRAY_SIZE>
ELEMENT_T const*
ArrayQueue<ELEMENT_T, ARRAY_SIZE>::front() const noexcept
{
	if (m_rear == m_front)
		return nullptr;
	return m_elements + m_front;
}

template<typename ELEMENT_T, int ARRAY_SIZE>
int __fastcall
ArrayQueue<ELEMENT_T, ARRAY_SIZE>::enqueue(ELEMENT_T const &element) noexcept
{
	int rear = m_rear;

	if (rear & STATE_FLAG_FULL)
		return -1;

	m_elements[rear] = element;
	rear = (rear + 1) % ARRAY_SIZE;
	if (rear == m_front)
		rear |= STATE_FLAG_FULL;
	m_rear = rear;
	return 0;
}

template<typename ELEMENT_T, int ARRAY_SIZE>
void
ArrayQueue<ELEMENT_T, ARRAY_SIZE>::dequeue() noexcept
{
	assert(m_rear != m_front);

	if(m_rear & STATE_FLAG_FULL)
		m_rear &= ~STATE_FLAG_FULL;
	m_front = (m_front + 1) % ARRAY_SIZE;
}

} // namespace Bee