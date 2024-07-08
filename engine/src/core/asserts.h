#pragma once

#include "defines.h"
#include <stdio.h>
// Disable assertions by commenting the below line
#define AGEASSERTIONS_ENABLE

#ifdef AGEASSERTIONS_ENABLE
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak();
#else
#define debugBreak() __builtin_trap();
#endif

AGEAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define AGEASSERT(expr)                                             \
    {                                                               \
        if (expr)                                                   \
        {                                                           \
        }                                                           \
        else                                                        \
        {                                                           \
            report_assertion_failure(#expr, "", __FILE__, __LINE__);\
            debugBreak();                                           \
        }                                                           \
    }

    
#define AGEASSERT_MSG(expr, message)                                        \
    {                                                                       \
        if (expr)                                                           \
        {                                                                   \
        }                                                                   \
        else                                                                \
        {                                                                   \
            report_assertion_failure(#expr, message, __FILE__, __LINE__);   \
            debugBreak();                                                   \
        }                                                                   \
    }                                                                       \

#ifdef _DEBUG
#define AGEASSERT_DEBUG(expr)                                           \
    {                                                                   \
        if (expr)                                                       \
        {                                                               \
        }                                                               \
        else                                                            \
        {                                                               \
            report_assertion_failure(#expr, "", __FILE__, __LINE__);    \
            debugBreak();                                               \
        }                                                               \
    }
#else
#define AGEASSERT_DEBUG(expr)
#endif

#else
#define AGEASSERT(expr)
#define AGEASSERT_MSG(expr, msg)
#define AGEASSERT_DEBUG(expr)
#endif