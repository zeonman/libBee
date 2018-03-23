/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 *
 * This method will cause each element belongs to one container only, but it can reduce the new allocation.
 */

#ifndef BEE_DATA_STRUCTURE_NODE_H_
#define BEE_DATA_STRUCTURE_NODE_H_

namespace Bee
{

struct SinglyNode
{
	SinglyNode *p_next;
};

struct DoublyNode
{
	DoublyNode *p_next;
	DoublyNode *p_previous;
};

} // namespace Bee

#endif // BEE_DATA_STRUCTURE_NODE_H_