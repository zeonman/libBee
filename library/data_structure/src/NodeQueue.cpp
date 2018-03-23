/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#include "bee/data_structure/NodeQueue.h"
#include <assert.h>
#include "bee/data_structure/node.h"

namespace Bee
{

void __fastcall
NodeQueue::enqueue(DoublyNode *p_node) noexcept
{
	assert(p_node);

	p_node->p_previous = mp_rear;
	p_node->p_next = nullptr;

	if (mp_rear)
		mp_rear->p_next = p_node;
	else
		mp_front = p_node;
	mp_rear = p_node;
}

DoublyNode*
NodeQueue::dequeue() noexcept
{
	DoublyNode *p_node = mp_front;
	if (p_node) {
		DoublyNode *p_next = p_node->p_next;
		if (p_next)
			p_next->p_previous = nullptr;
		else
			mp_rear = p_next;
		mp_front = p_next;
	}
	return p_node;
}

} // namespace Bee