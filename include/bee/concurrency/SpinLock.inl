/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#ifndef BEE_CONCURRENCY_SPIN_LOCK_INL_
#define BEE_CONCURRENCY_SPIN_LOCK_INL_

void
SpinLock::lock() noexcept
{
	while (Atomic::exchange(&m_flag, 1, Atomic::MEMORY_ORDER_ACQUIRE))
		;
}

void
SpinLock::unlock() noexcept
{
	Atomic::Store(&m_flag, 0, Atomic::MEMORY_ORDER_RELEASE);
}

#endif // BEE_CONCURRENCY_SPIN_LOCK_INL_