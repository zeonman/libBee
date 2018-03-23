/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#ifndef BEE_CONCURRENCY_COMPILER_MSVC_ATOMIC_INL_
#define BEE_CONCURRENCY_COMPILER_MSVC_ATOMIC_INL_

#define BEE_ATOMIC_WCHAR_T_SIZE		2
#define BEE_ATOMIC_SHORT_SIZE		2
#define BEE_ATOMIC_INT_SIZE			4
#define BEE_ATOMIC_LONG_SIZE		4
#define BEE_ATOMIC_LONGLONG_SIZE	8

#if (BEE_PLATFORM_BIT == 64)
#	define BEE_ATOMIC_ADDR_SIZE	8
#elif (BEE_PLATFORM_BIT == 32)
#	define BEE_ATOMIC_ADDR_SIZE	4
#else // BEE_PLATFORM_BIT
#	error	"This platform is not supported"
#endif // BEE_PLATFORM_BIT

#define BEE_ATOMIC_CONCATX(x, y) x ## y
#define BEE_ATOMIC_CONCAT(x, y) _CONCATX(x, y)
#define BEE_ATOMIC_STD_UINT BEE_ATOMIC_CONCAT(BEE_ATOMIC_CONCAT(std::_Uint, BEE_ATOMIC_SIZE), _t)

#define BEE_ATOMIC_TYPE	bool
#define BEE_ATOMIC_SIZE	1
#include "atomic_macro.inl"
#undef BEE_ATOMIC_TYPE
#undef BEE_ATOMIC_SIZE

#define BEE_ATOMIC_TYPE	char
#define BEE_ATOMIC_SIZE	1
#include "atomic_macro.inl"
#undef BEE_ATOMIC_TYPE
#undef BEE_ATOMIC_SIZE

#define BEE_ATOMIC_TYPE	signed char
#define BEE_ATOMIC_SIZE	1
#include "atomic_macro.inl"
#undef BEE_ATOMIC_TYPE
#undef BEE_ATOMIC_SIZE

#define BEE_ATOMIC_TYPE	unsigned char
#define BEE_ATOMIC_SIZE	1
#include "atomic_macro.inl"
#undef BEE_ATOMIC_TYPE
#undef BEE_ATOMIC_SIZE

#define BEE_ATOMIC_TYPE	char16_t
#define BEE_ATOMIC_SIZE	2
#include "atomic_macro.inl"
#undef BEE_ATOMIC_TYPE
#undef BEE_ATOMIC_SIZE

#define BEE_ATOMIC_TYPE	char32_t
#define BEE_ATOMIC_SIZE	4
#include "atomic_macro.inl"
#undef BEE_ATOMIC_TYPE
#undef BEE_ATOMIC_SIZE

#define BEE_ATOMIC_TYPE	wchar_t
#define BEE_ATOMIC_SIZE	BEE_ATOMIC_WCHAR_T_SIZE
#include "atomic_macro.inl"
#undef BEE_ATOMIC_TYPE
#undef BEE_ATOMIC_SIZE

#define BEE_ATOMIC_TYPE	short
#define BEE_ATOMIC_SIZE	BEE_ATOMIC_SHORT_SIZE
#include "atomic_macro.inl"
#undef BEE_ATOMIC_TYPE
#undef BEE_ATOMIC_SIZE

#define BEE_ATOMIC_TYPE	unsigned short
#define BEE_ATOMIC_SIZE	BEE_ATOMIC_SHORT_SIZE
#include "atomic_macro.inl"
#undef BEE_ATOMIC_TYPE
#undef BEE_ATOMIC_SIZE

#define BEE_ATOMIC_TYPE	int
#define BEE_ATOMIC_SIZE	BEE_ATOMIC_INT_SIZE
#include "atomic_macro.inl"
#undef BEE_ATOMIC_TYPE
#undef BEE_ATOMIC_SIZE

#define BEE_ATOMIC_TYPE	unsigned int
#define BEE_ATOMIC_SIZE	BEE_ATOMIC_INT_SIZE
#include "atomic_macro.inl"
#undef BEE_ATOMIC_TYPE
#undef BEE_ATOMIC_SIZE

#define BEE_ATOMIC_TYPE	long
#define BEE_ATOMIC_SIZE	BEE_ATOMIC_LONG_SIZE
#include "atomic_macro.inl"
#undef BEE_ATOMIC_TYPE
#undef BEE_ATOMIC_SIZE

#define BEE_ATOMIC_TYPE	unsigned long
#define BEE_ATOMIC_SIZE	BEE_ATOMIC_LONG_SIZE
#include "atomic_macro.inl"
#undef BEE_ATOMIC_TYPE
#undef BEE_ATOMIC_SIZE

#define BEE_ATOMIC_TYPE	long long
#define BEE_ATOMIC_SIZE	BEE_ATOMIC_LONGLONG_SIZE
#include "atomic_macro.inl"
#undef BEE_ATOMIC_TYPE
#undef BEE_ATOMIC_SIZE

#define BEE_ATOMIC_TYPE	unsigned long long
#define BEE_ATOMIC_SIZE	BEE_ATOMIC_LONGLONG_SIZE
#include "atomic_macro.inl"
#undef BEE_ATOMIC_TYPE
#undef BEE_ATOMIC_SIZE

#define BEE_ATOMIC_TYPE	void*
#define BEE_ATOMIC_SIZE	BEE_ATOMIC_ADDR_SIZE
#include "atomic_macro.inl"
#undef BEE_ATOMIC_TYPE
#undef BEE_ATOMIC_SIZE

#undef BEE_ATOMIC_WCHAR_T_SIZE
#undef BEE_ATOMIC_SHORT_SIZE
#undef BEE_ATOMIC_INT_SIZE
#undef BEE_ATOMIC_LONG_SIZE
#undef BEE_ATOMIC_LONGLONG_SIZE
#undef BEE_ATOMIC_ADDR_SIZE

#undef BEE_ATOMIC_STD_UINT
#undef BEE_ATOMIC_CONCAT
#undef BEE_ATOMIC_CONCATX

#endif // BEE_CONCURRENCY_COMPILER_MSVC_ATOMIC_INL_