/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 *
 * Suitable for situation when thread competition is low.
 * In my opinion, lock free is the special kind of spinlock which granularity is small
 * It doesn't afraid of thread suspended and lead to the other competitive threads wait in a loop.
 * (Because each time there must be one competitive thread satisfies when it spins.)
 */

#ifndef BEE_DATA_STRUCTURE_THREAD_SAFE_NODE_STACK_H_
#define BEE_DATA_STRUCTURE_THREAD_SAFE_NODE_STACK_H_

namespace Bee
{

struct SinglyNode;

namespace ThreadSafe
{

class NodeStack
{
public:
	inline NodeStack() noexcept = default;

	void __fastcall push(Bee::SinglyNode *p_node) noexcept;
	Bee::SinglyNode* pop() noexcept;

protected:
	Bee::SinglyNode* volatile mp_top = nullptr;
	Bee::SinglyNode* volatile mp_pop_node = nullptr;
};

}} // namespace Bee::ThreadSafe

#endif // BEE_DATA_STRUCTURE_THREAD_SAFE_NODE_STACK_H_