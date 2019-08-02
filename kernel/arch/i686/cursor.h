
#ifndef KERNEL_CURSOR_H
#define KERNEL_CURSOR_H

#include <stddef.h>

/** Cursor structure declaration */
typedef struct cursor_ {
    size_t x;  //!< X position
    size_t y;  //!< Y position
} cursor_t;

/**
 * Gets the cursor total offset
 *
 * @param cursor The cursor to get the offset of
 * @param width Width of the screen
 */
size_t cursor_offset(cursor_t cursor, size_t width);

/**
 * Updates the cursor position on the screen
 *
 * @param cursor The cursor
 * @param width Width of the screen
 */
void cursor_update(cursor_t cursor, size_t width);

#endif  // KERNEL_CURSOR_H
