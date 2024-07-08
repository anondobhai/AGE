#pragma once

// Unsigned int types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Signed int types
typedef char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

// floating points types
typedef float f32;
typedef double f64;

// boolean types
typedef int b32;
typedef char b8;

// Properlydefine static assertions 
#if defined (__clang__) || defined (__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// Ensure all types are of the correct size.
STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte");
STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be 2 bytes");
STATIC_ASSERT(sizeof(u32) == 4, "Expected u32 to be 4 bytes");
STATIC_ASSERT(sizeof(u64) == 8, "Expected u64 to be 8 bytes");

STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be 1 byte");
STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 bytes");
STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 bytes");
STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 bytes");

STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 bytes");
STATIC_ASSERT(sizeof(f64) == 8, "Expected i64 to be 8 bytes");

#define TRUE 1
#define FLASE 0

// Platform detection
#if defined (WIN32) || defined (_WIN32) || defined (__WIN23__)
#define AGEPLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit required on windows"alignas
#endif
#elif defined(__linux__) || defined(__gnu_linux__)
// Linux OS
#define AGEPLATFORM_LINUX 1
#if defined(__ANDROID__)
#define AGEPLATFORM_ANDRIOD 1
#endif
#elif defined(__unix__)
// Catch anything not caught by the above
#define AGEPLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
#define AGEPLATFORM_POSIX 1
#elseif __APPLE__
// Apple platform
#define AGEPLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
// IOS Simulator
#define AGEPLATFORM_IOS 1
#define AGEPLATFORM_IOS_SIMULATOR 1
// iOS device
#elif TARGET_OS_MAC
#error "Unknown Apple platform"AGEPLATFORM_APPLE
#endif
#else
#error "Unknown platform"
#endif

#ifdef AGEEXPORT
// Exports
#ifdef _MSC_VER
#define AGEAPI __declspec(dllexport)
#else
#define AGEAPI __attribute__((visibility("default")))
#endif
#else
// Imports
#ifndef _MSC_VER
#define AGEAPI __declspec(dllimport)
#else
#define AGEAPI
#endif
#endif