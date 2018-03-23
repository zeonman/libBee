/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#include "bee/data_structure/SinglyList.h"
#include <assert.h>
#include "bee/data_structure/node.h"

namespace Bee
{

void __fastcall
SinglyList::remove(SinglyNode const *p_node) noexcept
{
	assert(p_node);
	assert(mp_head);

	if (mp_head == p_node)
		mp_head = p_node->p_next;
	else {
		SinglyNode *p_cur = mp_head;
		while (p_cur->p_next != p_node) {
			p_cur = p_cur->p_next;
			assert(p_cur->p_next);
		}
		p_cur->p_next = p_node->p_next;
	}
}

} // namespace Bee