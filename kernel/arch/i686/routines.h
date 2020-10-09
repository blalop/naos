#pragma once

#include "types.h"

// Common and useful routines

void routines_memory_swap(void *a, void *b, size_t size);

void routines_memory_copy(void *dst, const void *src, size_t n);

void routines_memory_set(void *str, int c, size_t n);

void routines_int_to_ascii(int32_t n, char *str);
