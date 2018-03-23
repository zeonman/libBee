/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 *
 * Suitable for delay delete or multi producers-one cosumer mode.
 * Do not handle memory invalid or ABA problem caused by pop.
 */

#ifndef BEE_DATA_STRUCTURE_HALF_THREAD_SAFE_NODE_STACK_H_
#define BEE_DATA_STRUCTURE_HALF_THREAD_SAFE_NODE_STACK_H_

namespace Bee
{

struct SinglyNode;

namespace HalfThreadSafe
{

class NodeStack
{
public:
	inline NodeStack() noexcept = default;

	void __fastcall push(Bee::SinglyNode *p_node) noexcept;
	Bee::SinglyNode* pop() noexcept;

protected:
	Bee::SinglyNode* volatile mp_top = nullptr;
};

}} // namespace Bee::HalfThreadSafe

#endif // BEE_DATA_STRUCTURE_HALF_THREAD_SAFE_NODE_STACK_H_