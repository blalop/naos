#ifndef _STDIO_H
#define _STDIO_H 1

#include <stdarg.h>

int putchar(int c);
int puts(const char *str);
int vprintf(const char *fmt, va_list arg);
int printf(const char *fmt, ...);

#endif // _STDIO_H
