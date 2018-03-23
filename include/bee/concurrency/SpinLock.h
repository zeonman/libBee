/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#ifndef BEE_CONCURRENCY_SPIN_LOCK_H_
#define BEE_CONCURRENCY_SPIN_LOCK_H_

#include "atomic.h"

namespace Bee
{

class SpinLock
{
public:
	inline SpinLock() noexcept = default;
	SpinLock(SpinLock const&) = delete;
	SpinLock& operator=(SpinLock const&) = delete;

	inline void lock() noexcept;
	inline void unlock() noexcept;
protected:
	int volatile m_flag = 0;
};

#include "SpinLock.inl"

} // namespace Bee

#endif // BEE_CONCURRENCY_SPIN_LOCK_H_