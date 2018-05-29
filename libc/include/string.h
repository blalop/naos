#ifndef _STRING_H
#define _STRING_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void *memcpy(void *s1, void *s2, size_t n);
char *strcpy (char *destination, const char *source);
size_t strlen(const char *str);

#ifdef __cplusplus
}
#endif

#endif
