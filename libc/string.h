#pragma once

#include <stddef.h>

void *memcpy(void *dst, const void *src, size_t n);

void *memset(void *str, int c, size_t n);

int strcmp(const char *s1, const char *s2);

char *strcpy(char *dst, const char *src);

size_t strlen(const char *str);
