/*
* Copyright 2018 Zeonman.Lei
* License: GPLv3
* Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
* Source: https://github.com/zeonman/libBee
*/

#include "bee/data_structure/half_thread_safe/htsNodeStack.h"
#include <assert.h>
#include "bee/data_structure/node.h"
#include "bee/concurrency/atomic.h"

namespace Bee
{
namespace HalfThreadSafe
{

void __fastcall
NodeStack::push(Bee::SinglyNode *p_node) noexcept
{
	assert(p_node);
	p_node->p_next = Bee::Atomic::load(&mp_top, Bee::Atomic::MEMORY_ORDER_RELAXED);
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
	Bee::SinglyNode *p_node = Bee::Atomic::load(
															&mp_top,
															Bee::Atomic::MEMORY_ORDER_RELAXED);
	while (p_node && !Bee::Atomic::compare_exchange_weak(
												&mp_top,
												&p_node,
												p_node->p_next,
												Bee::Atomic::MEMORY_ORDER_RELEASE,
												Bee::Atomic::MEMORY_ORDER_RELAXED))
		;
	return p_node;
}

}} // namespace Bee::HalfThreadSafe