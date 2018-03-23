/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#include "bee/data_structure/thread_safe/tsNodeStack.h"
#include <assert.h>
#include "bee/data_structure/node.h"
#include "bee/concurrency/atomic.h"

namespace Bee
{
namespace ThreadSafe
{

void __fastcall
NodeStack::push(Bee::SinglyNode *p_node) noexcept
{
	assert(p_node);
	p_node->p_next = Bee::Atomic::load(
									&mp_top,
									Bee::Atomic::MEMORY_ORDER_RELAXED);
	while (!Bee::Atomic::compare_exchange_weak(
									&mp_top,
									&p_node->p_next,
									p_node,
									Bee::Atomic::MEMORY_ORDER_RELEASE,
									Bee::Atomic::MEMORY_ORDER_RELAXED))
		;
}

Bee::SinglyNode*
NodeStack::pop() noexcept
{
	Bee::SinglyNode *p_node;
	for (;;) {
		p_node = Bee::Atomic::load(
									&mp_top,
									Bee::Atomic::MEMORY_ORDER_CONSUME);
		if (!p_node) {
			Bee::Atomic::store(
									&mp_pop_node,
									p_node,
									Bee::Atomic::MEMORY_ORDER_RELEASE);
			break;
		}
		Bee::SinglyNode *p_old_pop_node = Bee::Atomic::exchange(
									&mp_pop_node,
									p_node,
									Bee::Atomic::MEMORY_ORDER_RELAXED);

		//To avoid p_node->mp_next memory invalid or ABA problem, don't snatch write competition
		if (p_node != p_old_pop_node) {
			if (Bee::Atomic::compare_exchange_weak(
									&mp_top,
									&p_node,
									p_node->p_next,
									Bee::Atomic::MEMORY_ORDER_RELEASE,
									Bee::Atomic::MEMORY_ORDER_RELAXED))
				break;
		}
	}
	return p_node;
}

}} // namespace Bee::ThreadSafe