#include "logger.h"
#include "asserts.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line)
{
    log_output(LOG_LEVEL_FATAL, "Assertion Failure: %s, message:'%s', in file: %s, line: %d\n", expression, message, file, line);
}

b8 initializeLogger()
{
    //TODO: create log file
    return TRUE;
}

void shutdownLogger()
{
    // TODO: cleanup logging/write queued entries.
}

void log_output(log_level level, const char* message, ...)
{
    const char* level_strings[6] =  { "[FATAL]: ", "[ERRO`R]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};
    //b8 isError = level < 2;

    // Not Recommended
    char out_message[32000];
    memset(out_message, 0, sizeof(out_message));

    __builtin_va_list arg_ptr;
    va_start(arg_ptr, message);
    vsnprintf(out_message, 32000, message, arg_ptr);
    va_end(arg_ptr);

    char out_message2[32000];
    sprintf(out_message2, "%s%s\n", level_strings[level], out_message);

    printf("%s", out_message2);
}

