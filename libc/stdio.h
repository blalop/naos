#pragma once

#include <stdarg.h>

int putchar(int c);
int puts(const char *restrict str);
int vprintf(const char *restrict fmt, va_list arg);
int printf(const char *restrict fmt, ...);

#ifndef NAOS_STRICT_POSIX
void clearscreen(void);
#endif  // NAOS_STRICT_POSIX
