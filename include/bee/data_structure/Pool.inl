/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#include <new>
#include <assert.h>

namespace Bee
{

template<class UNIT_T, typename COUNT_T, COUNT_T BLOCK_SIZE>
bool __fastcall
Pool<UNIT_T, COUNT_T, BLOCK_SIZE>::SubPool::is_contain(UNIT_T const *p_unit) const noexcept
{
	Unit const *p_inner_unit = (Unit const*)p_unit;
	return &m_units[p_inner_unit->index].unit == p_unit;
}

template<class UNIT_T, typename COUNT_T, COUNT_T BLOCK_SIZE>
Pool<UNIT_T, COUNT_T, BLOCK_SIZE>::~Pool()
{
	release();
}

template<class UNIT_T, typename COUNT_T, COUNT_T BLOCK_SIZE>
void
Pool<UNIT_T, COUNT_T, BLOCK_SIZE>::reset() noexcept
{
	release();
	m_list_sub_pool_in_use.reset();
	m_list_sub_pool_run_out.reset();
	m_list_sub_pool_free.reset();
}

template<class UNIT_T, typename COUNT_T, COUNT_T BLOCK_SIZE>
void
Pool<UNIT_T, COUNT_T, BLOCK_SIZE>::release() noexcept
{
	SubPool *p_next, *p_sub_pool;

	p_sub_pool = (SubPool*)m_list_sub_pool_in_use.head();
	while (p_sub_pool) {
		p_next = (SubPool*)p_sub_pool->p_next;
		delete p_sub_pool;
		p_sub_pool = p_next;
	}

	p_sub_pool = (SubPool*)m_list_sub_pool_run_out.head();
	while (p_sub_pool) {
		p_next = (SubPool*)p_sub_pool->p_next;
		delete p_sub_pool;
		p_sub_pool = p_next;
	}

	p_sub_pool = (SubPool*)m_list_sub_pool_free.head();
	while (p_sub_pool) {
		p_next = (SubPool*)p_sub_pool->p_next;
		delete p_sub_pool;
		p_sub_pool = p_next;
	}
}

template<class UNIT_T, typename COUNT_T, COUNT_T BLOCK_SIZE>
UNIT_T*
Pool<UNIT_T, COUNT_T, BLOCK_SIZE>::alloc() noexcept
{
	SubPool *p_sub_pool = (SubPool*)m_list_sub_pool_in_use.head();
	if (p_sub_pool) {
		UNIT_T *p_unit;
		if (p_sub_pool->alloc(&p_unit)) {
			m_list_sub_pool_in_use.remove(p_sub_pool);
			m_list_sub_pool_run_out.push_back(p_sub_pool);
		}
		assert(p_unit);
		return p_unit;
	}

	p_sub_pool = (SubPool*)m_list_sub_pool_free.pop_front();
	if (p_sub_pool) {
USE_SUB_POOL:
		UNIT_T *p_unit;
		if (p_sub_pool->alloc(&p_unit))
			m_list_sub_pool_run_out.push_back(p_sub_pool);
		else
			m_list_sub_pool_in_use.push_back(p_sub_pool);
		assert(p_unit);
		return p_unit;
	}

	p_sub_pool = new (std::nothrow) SubPool;
	if (p_sub_pool)
		goto USE_SUB_POOL;
	return nullptr;
}

template<class UNIT_T, typename COUNT_T, COUNT_T BLOCK_SIZE>
void __fastcall
Pool<UNIT_T, COUNT_T, BLOCK_SIZE>::free(UNIT_T const *p_unit) noexcept
{
	SubPool *p_sub_pool = (SubPool*)m_list_sub_pool_in_use.head();
	while (p_sub_pool) {
		if (p_sub_pool->is_contain(p_unit)) {
			if (p_sub_pool->free(p_unit)) {
				m_list_sub_pool_in_use.remove(p_sub_pool);
				m_list_sub_pool_free.push_back(p_sub_pool);
			}
			return;
		}
		p_sub_pool = (SubPool*)p_sub_pool->p_next;
	}

	p_sub_pool = (SubPool*)m_list_sub_pool_run_out.head();
	while (p_sub_pool) {
		if (p_sub_pool->is_contain(p_unit)) {
			m_list_sub_pool_run_out.remove(p_sub_pool);
			if (p_sub_pool->free(p_unit))
				m_list_sub_pool_free.push_back(p_sub_pool);
			else
				m_list_sub_pool_in_use.push_back(p_sub_pool);
			return;
		}
		p_sub_pool = (SubPool*)p_sub_pool->p_next;
	}
}

template<class UNIT_T, typename COUNT_T, COUNT_T BLOCK_SIZE>
bool __fastcall
Pool<UNIT_T, COUNT_T, BLOCK_SIZE>::SubPool::alloc(OUT UNIT_T **pp_unit) noexcept
{
	assert(pp_unit);

	if (m_free_cache_used) {
		COUNT_T free_index = m_free_cache[--m_free_cache_used];
		*pp_unit = &m_units[free_index].unit;
		return !m_free_cache_used && m_units_used == BLOCK_SIZE;
	}

	assert(m_units_used != BLOCK_SIZE);

	Unit *p_unit = m_units + m_units_used;
	p_unit->index = m_units_used++;

	*pp_unit = &p_unit->unit;
	return m_units_used == BLOCK_SIZE;
}

template<class UNIT_T, typename COUNT_T, COUNT_T BLOCK_SIZE>
bool __fastcall
Pool<UNIT_T, COUNT_T, BLOCK_SIZE>::SubPool::free(UNIT_T const *p_unit) noexcept
{
	assert(p_unit);

	Unit *p_inner_unit = (Unit*)p_unit;
	if (p_inner_unit->index == m_units_used - 1) {
		--m_units_used;
		return m_units_used == m_free_cache_used;
	}
	m_free_cache[m_free_cache_used++] = p_inner_unit->index;
	return false;
}

} // namespace Bee