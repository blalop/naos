#ifndef _STDLIB_H
#define _STDLIB_H 1

#include <stddef.h>

#ifndef NAOS_STRICT_POSIX
void itoa(int n, char *s);
void swap(void *a, void *b, size_t size);
#endif  // NAOS_STRICT_POSIX

#endif  // _STDLIB_H
