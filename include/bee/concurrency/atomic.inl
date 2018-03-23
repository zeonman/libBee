/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#ifndef BEE_CONCURRENCY_ATOMIC_INL_
#define BEE_CONCURRENCY_ATOMIC_INL_

#if defined(BEE_COMPILER_MSVC)
namespace Bee
{
namespace Msvc
{
namespace Atomic
{
#	include "compiler/msvc/atomic.inl"
}}} // namespace Bee::Msvc::Atomic
#endif // BEE_COMPILER_MSVC

namespace Bee
{
namespace Atomic
{

void
thread_fence(MemoryOrder memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_thread_fence(memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_thread_fence(memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return std::_Atomic_thread_fence((std::memory_order)memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

void
signal_fence(MemoryOrder memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_signal_fence(memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_signal_fence(memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return std::_Atomic_signal_fence((std::memory_order)memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
void
store(OPERAND_T volatile *ptr, OPERAND_T value, MemoryOrder memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	__c11_atomic_store(ptr, value, memory_order);
#elif defined(BEE_COMPILER_GNUC)
	__atomic_store_n(ptr, value, memory_order);
#elif defined(BEE_COMPILER_MSVC)
	Bee::Msvc::Atomic::macro_store(ptr, value, memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
OPERAND_T
load(OPERAND_T volatile *ptr, MemoryOrder memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_load(ptr, memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_load_n(ptr, memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return Bee::Msvc::Atomic::macro_load(ptr, memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
OPERAND_T
exchange(OPERAND_T volatile *ptr, OPERAND_T value, MemoryOrder memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_exchange(ptr, value, memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_exchange_n(ptr, value, memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return Bee::Msvc::Atomic::macro_exchange(ptr, value, memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
bool
compare_exchange_weak(OPERAND_T volatile *ptr, OPERAND_T *expected, OPERAND_T desired, MemoryOrder success_memory_order, MemoryOrder failure_memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_compare_exchange_weak(ptr, expected, desired, success_memory_order, failure_memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_compare_exchange_n(ptr, expected, desired, true, success_memory_order, failure_memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return Bee::Msvc::Atomic::macro_compare_exchange_weak(ptr, expected, desired, success_memory_order, failure_memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
bool
compare_exchange_strong(OPERAND_T volatile *ptr, OPERAND_T *expected, OPERAND_T desired, MemoryOrder success_memory_order, MemoryOrder failure_memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_compare_exchange_strong(ptr, expected, desired, success_memory_order, failure_memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_compare_exchange_n(ptr, expected, desired, false, success_memory_order, failure_memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return Bee::Msvc::Atomic::macro_compare_exchange_strong(ptr, expected, desired, success_memory_order, failure_memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
OPERAND_T
fetch_add(OPERAND_T volatile *ptr, OPERAND_T value, MemoryOrder memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_fetch_add(ptr, value, memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_fetch_add(ptr, value, memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return Bee::Msvc::Atomic::macro_fetch_add(ptr, value, memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
OPERAND_T
fetch_sub(OPERAND_T volatile *ptr, OPERAND_T value, MemoryOrder memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_fetch_sub(ptr, value, memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_fetch_sub(ptr, value, memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return Bee::Msvc::Atomic::macro_fetch_sub(ptr, value, memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
OPERAND_T
fetch_and(OPERAND_T volatile *ptr, OPERAND_T value, MemoryOrder memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_fetch_and(ptr, value, memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_fetch_and(ptr, value, memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return Bee::Msvc::Atomic::macro_fetch_and(ptr, value, memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
OPERAND_T
fetch_or(OPERAND_T volatile *ptr, OPERAND_T value, MemoryOrder memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_fetch_or(ptr, value, memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_fetch_or(ptr, value, memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return Bee::Msvc::Atomic::macro_fetch_or(ptr, value, memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
OPERAND_T
fetch_xor(OPERAND_T volatile *ptr, OPERAND_T value, MemoryOrder memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_fetch_xor(ptr, value, memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_fetch_xor(ptr, value, memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return Bee::Msvc::Atomic::macro_fetch_xor(ptr, value, memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
void
store(OPERAND_T* volatile *ptr, OPERAND_T *value, MemoryOrder memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	__c11_atomic_store(ptr, value, memory_order);
#elif defined(BEE_COMPILER_GNUC)
	__atomic_store_n(ptr, value, memory_order);
#elif defined(BEE_COMPILER_MSVC)
	Bee::Msvc::Atomic::macro_store((void* volatile*)ptr, (void*)value, memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
OPERAND_T*
load(OPERAND_T* volatile *ptr, MemoryOrder memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_load(ptr, memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_load_n(ptr, memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return (OPERAND_T*)Bee::Msvc::Atomic::macro_load((void* volatile*)ptr, memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
OPERAND_T*
exchange(OPERAND_T* volatile *ptr, OPERAND_T* value, MemoryOrder memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_exchange(ptr, value, memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_exchange_n(ptr, value, memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return (OPERAND_T*)Bee::Msvc::Atomic::macro_exchange((void* volatile*)ptr, (void*)value, memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
bool
compare_exchange_weak(OPERAND_T* volatile *ptr, OPERAND_T **expected, OPERAND_T *desired, MemoryOrder success_memory_order, MemoryOrder failure_memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_compare_exchange_weak(ptr, expected, desired, success_memory_order, failure_memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_compare_exchange_n(ptr, expected, desired, true, success_memory_order, failure_memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return Bee::Msvc::Atomic::macro_compare_exchange_weak((void* volatile*)ptr, (void**)expected, (void*)desired, success_memory_order, failure_memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
bool
compare_exchange_strong(OPERAND_T* volatile *ptr, OPERAND_T **expected, OPERAND_T *desired, MemoryOrder success_memory_order, MemoryOrder failure_memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_compare_exchange_strong(ptr, expected, desired, success_memory_order, failure_memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_compare_exchange_n(ptr, expected, desired, false, success_memory_order, failure_memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return Bee::Msvc::Atomic::macro_compare_exchange_strong((void* volatile*)ptr, (void**)expected, (void*)desired, success_memory_order, failure_memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
OPERAND_T*
fetch_add(OPERAND_T* volatile *ptr, OPERAND_T *value, MemoryOrder memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_fetch_add(ptr, value, memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_fetch_add(ptr, value, memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return (OPERAND_T*)Bee::Msvc::Atomic::macro_fetch_add((void* volatile*)ptr, (void*)value, memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
OPERAND_T*
fetch_sub(OPERAND_T* volatile *ptr, OPERAND_T *value, MemoryOrder memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_fetch_sub(ptr, value, memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_fetch_sub(ptr, value, memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return (OPERAND_T*)Bee::Msvc::Atomic::macro_fetch_sub((void* volatile*)ptr, (void*)value, memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
OPERAND_T*
fetch_and(OPERAND_T* volatile *ptr, OPERAND_T *value, MemoryOrder memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_fetch_and(ptr, value, memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_fetch_and(ptr, value, memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return (OPERAND_T*)Bee::Msvc::Atomic::macro_fetch_and((void* volatile*)ptr, (void*)value, memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
OPERAND_T*
fetch_or(OPERAND_T* volatile *ptr, OPERAND_T *value, MemoryOrder memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_fetch_or(ptr, value, memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_fetch_or(ptr, value, memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return (OPERAND_T*)Bee::Msvc::Atomic::macro_fetch_or((void* volatile*)ptr, (void*)value, memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

template<typename OPERAND_T>
OPERAND_T*
fetch_xor(OPERAND_T* volatile *ptr, OPERAND_T *value, MemoryOrder memory_order) noexcept
{
#if defined(BEE_COMPILER_CLANG)
	return __c11_atomic_fetch_xor(ptr, value, memory_order);
#elif defined(BEE_COMPILER_GNUC)
	return __atomic_fetch_xor(ptr, value, memory_order);
#elif defined(BEE_COMPILER_MSVC)
	return (OPERAND_T*)Bee::Msvc::Atomic::macro_fetch_xor((void* volatile*)ptr, (void*)value, memory_order);
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX
}

}} // namespace Bee::Atomic

#endif // BEE_CONCURRENCY_ATOMIC_INL_