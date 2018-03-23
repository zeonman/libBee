/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#include "bee/data_structure/List.h"
#include <assert.h>
#include "bee/data_structure/node.h"

namespace Bee
{

void __fastcall
List::push_front(DoublyNode *p_node) noexcept
{
	assert(p_node);

	p_node->p_previous = nullptr;
	if (mp_head) {
		p_node->p_next = mp_head;
		mp_head = mp_head->p_previous = p_node;
	}
	else {
		p_node->p_next = nullptr;
		mp_head = mp_tail = p_node;
	}
}

DoublyNode*
List::pop_front() noexcept
{
	DoublyNode *p_node = mp_head;
	if (p_node) {
		DoublyNode *p_next = p_node->p_next;
		if (p_next)
			p_next->p_previous = nullptr;
		else
			mp_tail = nullptr;
		mp_head = p_next;
	}
	return p_node;
}

void __fastcall
List::push_back(DoublyNode *p_node) noexcept
{
	assert(p_node);

	p_node->p_next = nullptr;
	if (mp_head) {
		p_node->p_previous = mp_tail;
		mp_tail = mp_tail->p_next = p_node;
	} else {
		p_node->p_previous = nullptr;
		mp_head = mp_tail = p_node;
	}
}

DoublyNode*
List::pop_back() noexcept
{
	DoublyNode *p_node = mp_tail;
	if (p_node) {
		DoublyNode *p_previous = p_node->p_previous;
		if (p_previous)
			p_previous->p_next = nullptr;
		else
			mp_head = nullptr;
		mp_tail = p_previous;
	}
	return p_node;
}

void __fastcall
List::remove(DoublyNode const *p_node) noexcept
{
	assert(p_node);
	assert(mp_head);

	if (mp_head == p_node)
		mp_head = p_node->p_next;
	else
		p_node->p_previous->p_next = p_node->p_next;

	if (mp_tail == p_node)
		mp_tail = p_node->p_previous;
	else
		p_node->p_next->p_previous = p_node->p_previous;
}

} // namespace Bee