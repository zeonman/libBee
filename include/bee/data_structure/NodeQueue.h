/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#ifndef BEE_DATA_STRUCTURE_NODE_QUEUE_H_
#define BEE_DATA_STRUCTURE_NODE_QUEUE_H_

namespace Bee
{

struct DoublyNode;

class NodeQueue
{
public:
	inline NodeQueue() noexcept = default;

	inline bool is_empty() const noexcept;
	inline DoublyNode* front() noexcept;
	inline DoublyNode const* front() const noexcept;
	inline DoublyNode* rear() noexcept;
	inline DoublyNode const* rear() const noexcept;

	void __fastcall enqueue(DoublyNode *p_node) noexcept;
	DoublyNode* dequeue() noexcept;

protected:
	DoublyNode *mp_front = nullptr;
	DoublyNode *mp_rear = nullptr;
};

bool
NodeQueue::is_empty() const noexcept
{
	return mp_front == nullptr;
}

DoublyNode*
NodeQueue::front() noexcept
{
	return mp_front;
}

DoublyNode const*
NodeQueue::front() const noexcept
{
	return mp_front;
}

DoublyNode*
NodeQueue::rear() noexcept
{
	return mp_rear;
}

DoublyNode const*
NodeQueue::rear() const noexcept
{
	return mp_rear;
}

} // namespace Bee

#endif // BEE_DATA_STRUCTURE_NODE_QUEUE_H_