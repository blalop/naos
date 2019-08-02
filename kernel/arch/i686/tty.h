/**
 * @file
 * @brief TTY related functionality.
 *
 */

#ifndef KERNEL_TTY_H
#define KERNEL_TTY_H

/**
 * Available VGA Colors
 */
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

/**
 * Print the parameter in the correspondent place
 *
 * @param c The character to be printed
 */
void tty_print(char c);

/**
 * Print the parameter in the correspondent place with color
 *
 * @param c The character to be printed
 * @param fg The foreground color
 * @param bg The background color
 */
void tty_printc(char c, vgacolor_t fg, vgacolor_t bg);

/**
 * @brief Clears the TTY
 */
void tty_clear(void);

#endif  // KERNEL_TTY_H
