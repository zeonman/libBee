/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 *
 * thread unsafe.
 * alloc won't initalize UNIT_T.
 *
 * UNIT_T is used in template instead of UNIT_SIZE, because it's common to visit data with same type.
 * Put data with same type together is good for performance no matter in swap memory page's view or cache line's view.
 */

#ifndef BEE_DATA_STRUCTURE_POOL_H_
#define BEE_DATA_STRUCTURE_POOL_H_

#include "List.h"
#include "node.h"
#include "bee/common/define.h"

namespace Bee
{

template<class UNIT_T, typename COUNT_T = unsigned int, COUNT_T BLOCK_SIZE = 30>
class Pool final
{
	static_assert(BLOCK_SIZE > 0, "BLOCK_SIZE <= 0");

public:
	~Pool() noexcept;
	void reset() noexcept;

protected:
	void release() noexcept;

public:
	UNIT_T* alloc() noexcept;
	void __fastcall free(UNIT_T const *p_unit) noexcept;

protected:
	struct Unit
	{
		UNIT_T unit;
		COUNT_T index;
	};

	class SubPool : public DoublyNode
	{
	public:
		inline SubPool() noexcept = default;

		bool __fastcall alloc(OUT UNIT_T **pp_unit) noexcept; // Return true on run out
		bool __fastcall free(UNIT_T const *p_unit) noexcept; // Return true when all units are free

		inline bool __fastcall is_contain(UNIT_T const *p_unit) const noexcept;

	protected:
		Unit m_units[BLOCK_SIZE];
		COUNT_T m_units_used = 0;

		COUNT_T m_free_cache_used = 0;
		COUNT_T m_free_cache[BLOCK_SIZE];
	};

protected:
	List m_list_sub_pool_in_use;
	List m_list_sub_pool_run_out;
	List m_list_sub_pool_free;
};

} // namespace Bee

#include "Pool.inl"

#endif // BEE_DATA_STRUCTURE_POOL_H_