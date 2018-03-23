/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

static_assert(BEE_ATOMIC_SIZE == sizeof(BEE_ATOMIC_TYPE), "BEE_ATOMIC_SIZE and BEE_ATOMIC_TYPE should match.");

inline void
macro_store(BEE_ATOMIC_TYPE volatile *ptr, BEE_ATOMIC_TYPE value, Bee::Atomic::MemoryOrder memory_order) noexcept
{
	BEE_ATOMIC_CONCAT(std::_Atomic_store_, BEE_ATOMIC_SIZE)
				((BEE_ATOMIC_STD_UINT volatile*)ptr, (BEE_ATOMIC_STD_UINT)value, (std::memory_order)memory_order);
}

inline BEE_ATOMIC_TYPE
macro_load(BEE_ATOMIC_TYPE volatile *ptr, Bee::Atomic::MemoryOrder memory_order) noexcept
{
	return (BEE_ATOMIC_TYPE)BEE_ATOMIC_CONCAT(std::_Atomic_load_, BEE_ATOMIC_SIZE)
				((BEE_ATOMIC_STD_UINT volatile*)ptr, (std::memory_order)memory_order);
}

inline BEE_ATOMIC_TYPE
macro_exchange(BEE_ATOMIC_TYPE volatile *ptr, BEE_ATOMIC_TYPE value, Bee::Atomic::MemoryOrder memory_order) noexcept
{
	return (BEE_ATOMIC_TYPE)BEE_ATOMIC_CONCAT(std::_Atomic_exchange_, BEE_ATOMIC_SIZE)
				((BEE_ATOMIC_STD_UINT volatile*)ptr, (BEE_ATOMIC_STD_UINT)value, (std::memory_order)memory_order);
}

inline bool
macro_compare_exchange_weak(BEE_ATOMIC_TYPE volatile *ptr, BEE_ATOMIC_TYPE *expected, BEE_ATOMIC_TYPE desired, Bee::Atomic::MemoryOrder success_memory_order, Bee::Atomic::MemoryOrder failure_memory_order) noexcept
{
	return BEE_ATOMIC_CONCAT(std::_Atomic_compare_exchange_weak_, BEE_ATOMIC_SIZE)
				((BEE_ATOMIC_STD_UINT volatile*)ptr, (BEE_ATOMIC_STD_UINT*)expected, (BEE_ATOMIC_STD_UINT)desired, (std::memory_order)success_memory_order, (std::memory_order)failure_memory_order);
}

inline bool
macro_compare_exchange_strong(BEE_ATOMIC_TYPE volatile *ptr, BEE_ATOMIC_TYPE *expected, BEE_ATOMIC_TYPE desired, Bee::Atomic::MemoryOrder success_memory_order, Bee::Atomic::MemoryOrder failure_memory_order) noexcept
{
	return BEE_ATOMIC_CONCAT(std::_Atomic_compare_exchange_strong_, BEE_ATOMIC_SIZE)
				((BEE_ATOMIC_STD_UINT volatile*)ptr, (BEE_ATOMIC_STD_UINT*)expected, (BEE_ATOMIC_STD_UINT)desired, (std::memory_order)success_memory_order, (std::memory_order)failure_memory_order);
}

inline BEE_ATOMIC_TYPE
macro_fetch_add(BEE_ATOMIC_TYPE volatile *ptr, BEE_ATOMIC_TYPE value, Bee::Atomic::MemoryOrder memory_order) noexcept
{
	return (BEE_ATOMIC_TYPE)BEE_ATOMIC_CONCAT(std::_Atomic_fetch_add_, BEE_ATOMIC_SIZE)
				((BEE_ATOMIC_STD_UINT volatile*)ptr, (BEE_ATOMIC_STD_UINT)value, (std::memory_order)memory_order);
}

inline BEE_ATOMIC_TYPE
macro_fetch_sub(BEE_ATOMIC_TYPE volatile *ptr, BEE_ATOMIC_TYPE value, Bee::Atomic::MemoryOrder memory_order) noexcept
{
	return (BEE_ATOMIC_TYPE)BEE_ATOMIC_CONCAT(std::_Atomic_fetch_sub_, BEE_ATOMIC_SIZE)
				((BEE_ATOMIC_STD_UINT volatile*)ptr, (BEE_ATOMIC_STD_UINT)value, (std::memory_order)memory_order);
}

inline BEE_ATOMIC_TYPE
macro_fetch_and(BEE_ATOMIC_TYPE volatile *ptr, BEE_ATOMIC_TYPE value, Bee::Atomic::MemoryOrder memory_order) noexcept
{
	return (BEE_ATOMIC_TYPE)BEE_ATOMIC_CONCAT(std::_Atomic_fetch_and_, BEE_ATOMIC_SIZE)
				((BEE_ATOMIC_STD_UINT volatile*)ptr, (BEE_ATOMIC_STD_UINT)value, (std::memory_order)memory_order);
}

inline BEE_ATOMIC_TYPE
macro_fetch_or(BEE_ATOMIC_TYPE volatile *ptr, BEE_ATOMIC_TYPE value, Bee::Atomic::MemoryOrder memory_order) noexcept
{
	return (BEE_ATOMIC_TYPE)BEE_ATOMIC_CONCAT(std::_Atomic_fetch_or_, BEE_ATOMIC_SIZE)
				((BEE_ATOMIC_STD_UINT volatile*)ptr, (BEE_ATOMIC_STD_UINT)value, (std::memory_order)memory_order);
}

inline BEE_ATOMIC_TYPE
macro_fetch_xor(BEE_ATOMIC_TYPE volatile *ptr, BEE_ATOMIC_TYPE value, Bee::Atomic::MemoryOrder memory_order) noexcept
{
	return (BEE_ATOMIC_TYPE)BEE_ATOMIC_CONCAT(std::_Atomic_fetch_xor_, BEE_ATOMIC_SIZE)
				((BEE_ATOMIC_STD_UINT volatile*)ptr, (BEE_ATOMIC_STD_UINT)value, (std::memory_order)memory_order);
}