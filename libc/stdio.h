#ifndef _STDIO_H
#define _STDIO_H 1

#include <stdarg.h>

int putchar(int c);
int puts(const char *restrict str);
int vprintf(const char *restrict fmt, va_list arg);
int printf(const char *restrict fmt, ...);

#ifndef NAOS_STRICT_POSIX
void clearscreen(void);
#endif  // NAOS_STRICT_POSIX

#endif  // _STDIO_H
