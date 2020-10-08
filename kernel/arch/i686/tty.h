/**
 * @file
 * @brief TTY related functionality.
 *
 */

#pragma once

typedef enum vgacolor_ {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHT_GRAY,
    DARK_GRAY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_CYAN,
    LIGHT_RED,
    LIGHT_MAGENTA,
    LIGHT_YELLOW,
    WHITE,
} vgacolor_t;

void tty_print(char c);

void tty_printc(char c, vgacolor_t fg, vgacolor_t bg);

void tty_clear(void);
