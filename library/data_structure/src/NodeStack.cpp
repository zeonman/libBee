/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#include "bee/data_structure/NodeStack.h"
#include <assert.h>
#include "bee/data_structure/node.h"

namespace Bee
{

void __fastcall
NodeStack::push(SinglyNode *p_node) noexcept
{
	assert(p_node);

	p_node->p_next = mp_top;
	mp_top = p_node;
}

SinglyNode*
NodeStack::pop() noexcept
{
	SinglyNode *p_node = mp_top;
	if (p_node)
		mp_top = p_node->p_next;
	return p_node;
}

} // namespace Bee