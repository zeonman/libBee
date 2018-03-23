/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#ifndef BEE_CONCURRENCY_ATOMIC_H_
#define BEE_CONCURRENCY_ATOMIC_H_

#include "bee/common/platform.h"

#if defined(BEE_COMPILER_MSVC)
#	include <xatomic.h>
#endif // BEE_COMPILER_XXXX

namespace Bee
{
namespace Atomic
{

#if defined(BEE_COMPILER_CLANG) || defined(BEE_COMPILER_GNUC)
typedef enum MemoryOrder
{
	MEMORY_ORDER_RELAXED = __ATOMIC_RELAXED,
	MEMORY_ORDER_CONSUME = __ATOMIC_CONSUME,
	MEMORY_ORDER_ACQUIRE = __ATOMIC_ACQUIRE,
	MEMORY_ORDER_RELEASE = __ATOMIC_RELEASE,
	MEMORY_ORDER_ACQ_REL = __ATOMIC_ACQ_REL,
	MEMORY_ORDER_SEQ_CST = __ATOMIC_SEQ_CST
} MemoryOrder;
#elif defined(BEE_COMPILER_MSVC)
typedef enum MemoryOrder
{
		MEMORY_ORDER_RELAXED = std::memory_order_relaxed,
		MEMORY_ORDER_CONSUME = std::memory_order_consume,
		MEMORY_ORDER_ACQUIRE = std::memory_order_acquire,
		MEMORY_ORDER_RELEASE = std::memory_order_release,
		MEMORY_ORDER_ACQ_REL = std::memory_order_acq_rel,
		MEMORY_ORDER_SEQ_CST = std::memory_order_seq_cst
} MemoryOrder;
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX

inline void thread_fence(MemoryOrder memory_order) noexcept;
inline void signal_fence(MemoryOrder memory_order) noexcept;

template<typename OPERAND_T>
inline void
store(OPERAND_T volatile *ptr, OPERAND_T value, MemoryOrder memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline OPERAND_T
load(OPERAND_T volatile *ptr, MemoryOrder memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline OPERAND_T
exchange(OPERAND_T volatile *ptr, OPERAND_T value, MemoryOrder memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline bool
compare_exchange_weak(OPERAND_T volatile *ptr, OPERAND_T *expected, OPERAND_T desired, MemoryOrder success_memory_order = MEMORY_ORDER_SEQ_CST, MemoryOrder failure_memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline bool
compare_exchange_strong(OPERAND_T volatile *ptr, OPERAND_T *expected, OPERAND_T desired, MemoryOrder success_memory_order = MEMORY_ORDER_SEQ_CST, MemoryOrder failure_memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline OPERAND_T
fetch_add(OPERAND_T volatile *ptr, OPERAND_T value, MemoryOrder memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline OPERAND_T
fetch_sub(OPERAND_T volatile *ptr, OPERAND_T value, MemoryOrder memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline OPERAND_T
fetch_and(OPERAND_T volatile *ptr, OPERAND_T value, MemoryOrder memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline OPERAND_T
fetch_or(OPERAND_T volatile *ptr, OPERAND_T value, MemoryOrder memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline OPERAND_T
fetch_xor(OPERAND_T volatile *ptr, OPERAND_T value, MemoryOrder memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline void
store(OPERAND_T* volatile *ptr, OPERAND_T *value, MemoryOrder memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline OPERAND_T*
load(OPERAND_T* volatile *ptr, MemoryOrder memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline OPERAND_T*
exchange(OPERAND_T* volatile *ptr, OPERAND_T* value, MemoryOrder memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline bool
compare_exchange_weak(OPERAND_T* volatile *ptr, OPERAND_T **expected, OPERAND_T *desired, MemoryOrder success_memory_order = MEMORY_ORDER_SEQ_CST, MemoryOrder failure_memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline bool
compare_exchange_strong(OPERAND_T* volatile *ptr, OPERAND_T **expected, OPERAND_T *desired, MemoryOrder success_memory_order = MEMORY_ORDER_SEQ_CST, MemoryOrder failure_memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline OPERAND_T*
fetch_add(OPERAND_T* volatile *ptr, OPERAND_T *value, MemoryOrder memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline OPERAND_T*
fetch_sub(OPERAND_T* volatile *ptr, OPERAND_T *value, MemoryOrder memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline OPERAND_T*
fetch_and(OPERAND_T* volatile *ptr, OPERAND_T *value, MemoryOrder memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline OPERAND_T*
fetch_or(OPERAND_T* volatile *ptr, OPERAND_T *value, MemoryOrder memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

template<typename OPERAND_T>
inline OPERAND_T*
fetch_xor(OPERAND_T* volatile *ptr, OPERAND_T *value, MemoryOrder memory_order = MEMORY_ORDER_SEQ_CST) noexcept;

}} // namespace Bee::Atomic

#include "atomic.inl"

#endif // BEE_CONCURRENCY_ATOMIC_H_