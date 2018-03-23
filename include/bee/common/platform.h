/*
 * Copyright 2018 Zeonman.Lei
 * License: GPLv3
 * Author: Zeonman.Lei (Zeonman.Lei@gmail.com)
 * Source: https://github.com/zeonman/libBee
 */

#ifndef BEE_COMMON_PLATFORM_H_
#define BEE_COMMON_PLATFORM_H_

#define BEE_OS_SPEC_POSIX	(0x1 << 15)

#if !defined(BEE_TARGET_PLATFORM)
#	if defined(_WIN32) || defined(_WIN64)
#		define	BEE_PLATFORM_WINDOWS	(0x1)
#		define	BEE_TARGET_PLATFORM	BEE_PLATFORM_WINDOWS
#	elif defined(__linux__) || defined(__linux)
#		define	BEE_PLATFORM_LINUX	(BEE_OS_SPEC_POSIX | 0x1)
#		define	BEE_TARGET_PLATFORM	BEE_PLATFORM_LINUX
#	elif defined(__FreeBSD__)
#		define	BEE_PLATFORM_FREEBSD	(BEE_OS_SPEC_POSIX | 0x2)
#		define	BEE_TARGET_PLATFORM	BEE_PLATFORM_FREEBSD
#	elif defined(__ios)
#		define	BEE_PLATFORM_IOS	(BEE_OS_SPEC_POSIX | 0x3)
#		define	BEE_TARGET_PLATFORM	BEE_PLATFORM_IOS
#	elif defined(__macos)
#		define	BEE_PLATFORM_MACOS	(BEE_OS_SPEC_POSIX | 0x4)
#		define	BEE_TARGET_PLATFORM	BEE_PLATFORM_MACOS
#	elif defined(__ANDROID__)
#		define	BEE_PLATFORM_ANDROID	(BEE_OS_SPEC_POSIX | 0x5)
#		define	BEE_TARGET_PLATFORM	BEE_PLATFORM_ANDROID
#	else // BEE_PLATFORM_XXXX
#		error	"This os is not supported"
#	endif // BEE_PLATFORM_XXXX
#endif // BEE_TARGET_PLATFORM

#if defined(__clang__)
#	define	BEE_COMPILER_CLANG	((__clang_major__ * 100) + __clang_minor__)
#elif defined(__GNUC__)
#	define	BEE_COMPILER_GNUC	(__GNUC__ * 100 + __GNUC_MINOR__)
#	if defined(__LP64__)
#		define BEE_PLATFORM_BIT	64
#	elif defined(__LP32__)
#		define BEE_PLATFORM_BIT	32
#	else // __LPxx__
#		error	"This platform is not supported"
#	endif // __LPxx__
#elif defined(_MSC_VER)
#	define	BEE_COMPILER_MSVC	(_MSC_VER)
#	if defined(_WIN64)
#		define BEE_PLATFORM_BIT	64
#	elif defined(_WIN32)
#		define BEE_PLATFORM_BIT	32
#	else // _WINxx
#		error	"This platform is not supported"
#	endif // _WINxx
#elif defined(__INTEL_COMPILER)
#	define	BEE_COMPILER_INTEL	(__INTEL_COMPILER)
#else // BEE_COMPILER_XXXX
#	error	"This compiler is not supported"
#endif // BEE_COMPILER_XXXX

#if !defined(BEE_DECL_EXPORT)
#	if defined(BEE_COMPILER_MSVC)
#		define	BEE_DECL_EXPORT	__declspec(dllexport)
#	elif defined(BEE_COMPILER_GNUC)
#		define	BEE_DECL_EXPORT	__attribute__((visibility("default")))
#	else // BEE_COMPILER_XXXX
#		error	"This os is not supported"
#	endif // BEE_COMPILER_XXXX
#endif // BEE_DECL_EXPORT

#if !defined(BEE_DECL_IMPORT)
#	if defined(BEE_COMPILER_MSVC)
#		define	BEE_DECL_IMPORT	__declspec(dllimport)
#	elif defined(BEE_COMPILER_GNUC)
#		define	BEE_DECL_IMPORT
#	else // BEE_COMPILER_XXXX
#		error	"This os is not supported"
#	endif // BEE_COMPILER_XXXX
#endif // BEE_DECL_IMPORT

#endif // BEE_COMMON_PLATFORM_H_