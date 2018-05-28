#ifndef NAOS_STRING_H
#define NAOS_MEMORY_H

#include <stdint.h>
#include <stddef.h>

void *memcpy(void *s1, void *s2, size_t n);
char *strcpy (char *destination, const char *source);
size_t strlen(const char *str);

#endif

