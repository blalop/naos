
#ifndef KERNEL_TTY_H
#define KERNEL_TTY_H

#include <stddef.h>

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

void tty_kprint(char c);
void tty_kprint_color(char c, vgacolor_t fg, vgacolor_t bg);
void tty_kdraw(char c, size_t col, size_t row, vgacolor_t fg, vgacolor_t bg);
void tty_clear_screen(void);

#endif // KERNEL_TTY_H
