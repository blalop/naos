#pragma once

#include "types.h"

typedef struct cursor_ {
    size_t x;
    size_t y;
} cursor_t;

size_t cursor_offset(cursor_t cursor, size_t width);

void cursor_update(cursor_t cursor, size_t width);
