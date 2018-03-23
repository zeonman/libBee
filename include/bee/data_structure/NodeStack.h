/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#ifndef BEE_DATA_STRUCTURE_NODE_STACK_H_
#define BEE_DATA_STRUCTURE_NODE_STACK_H_

namespace Bee
{

struct SinglyNode;

class NodeStack
{
public:
	inline NodeStack() noexcept = default;

	void __fastcall push(SinglyNode *p_node) noexcept;
	SinglyNode* pop() noexcept;

protected:
	SinglyNode *mp_top = nullptr;
};

} // namespace Bee

#endif // BEE_DATA_STRUCTURE_NODE_STACK_H_