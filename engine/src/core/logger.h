#pragma once
#include <defines.h>

#define LOG_WARN_ENABLE 1
#define LOG_INFO_ENABLE 1
#define LOG_DEBUG_ENABLE 1
#define LOG_TRACE_ENABLE 1

// Disable the debug and trace logging for release build 
#if AGERELEASE == 1
#define LOG_DEBUG_ENABLE 0
#define LOG_TRACE_ENABLE 0
#endif

typedef enum log_level 
{
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5
} log_level;

b8 initializeLogger();
void shutdownLogger();

AGEAPI void log_output(log_level level, const char* message, ...);

// logs a fatal-level message
#define AGEFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);

#ifndef AGEERROR
// Logs an error-level message
#define AGEERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLE == 1
// Logs a warning message
#define AGEWARN(message, ...) log_output(LOG_LEVEL_WARNING, message, ##__VA_ARGS__);
#else
// Does Nothing when LOG_WARN_ENABLE != 1
#define AGEWARN(message, ...);
#endif

#if LOG_INFO_ENABLE == 1
// Logs a info-level message
#define AGEINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
// Does Nothing when LOG_INFO_ENABLE != 1
#define AGEINFO(message, ...);
#endif

#if LOG_DEBUG_ENABLE == 1
// Logs a Debug-level message
#define AGEDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
// Does Nothing when LOG_DEBUG_ENABLE != 1
#define AGEDEBUG(message, ...);
#endif

#if LOG_TRACE_ENABLE == 1
// Logs a trace-level message
#define AGETRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
// Does Nothing when LOG_TRACE_ENABLE != 1
#define AGETRACE(message, ...);
#endif

