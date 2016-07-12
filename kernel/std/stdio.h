#ifndef _STD_STDIO_H_
#define _STD_STDIO_H_

#include "stdarg.h"
#include "types.h"

#define PRINTF_BUFFER_SIZE 100

// printf remakes
int vsnoutput(char *buffer, size_t size, const char *format, va_list ap);
int snoutput(char *buffer, size_t size, const char *format, ...);
int voutput(const char *format, va_list ap);
int output(const char *format, ...);

#endif
