
#include "tty.h"

#include <stddef.h>
#include <stdint.h>

#include "cursor.h"

static const size_t MAX_ROWS = 25;
static const size_t MAX_COLS = 80;
static uint16_t *const VIDEO_ADDRESS = (uint16_t *)0xB8000;
static volatile cursor_t cursor;

static inline uint16_t vga_entry(char c, vgacolor_t fg, vgacolor_t bg) {
    uint8_t color = bg << 4 | fg;
    return color << 8 | c;
}

void tty_print(char c) { tty_printc(c, LIGHT_GRAY, BLACK); }

void tty_printc(char c, vgacolor_t fg, vgacolor_t bg) {
    switch (c) {
        case '\b':
            if (cursor.x > 0) {
                cursor.x--;
            }
            break;
        case '\n':
            cursor.x = 0;
            cursor.y++;
            break;
        case '\r':
            cursor.x = 0;
            break;
        case '\t':
            cursor.x = (cursor.x + 8) & ~(8 - 1);
            break;
        case ' ' ... '~':
            VIDEO_ADDRESS[cursor_offset(cursor, MAX_COLS)] =
                vga_entry(c, fg, bg);
            cursor.x++;
            break;
    }

    if (cursor.x >= MAX_COLS) {  // new line
        cursor.x = 0;
        cursor.y++;
    }

    if (cursor.y >= MAX_ROWS) {  // scroll
        for (size_t i = 0; i < MAX_COLS * (MAX_ROWS - 1); i++) {
            VIDEO_ADDRESS[i] = VIDEO_ADDRESS[i + MAX_COLS];
        }
        for (size_t i = MAX_COLS * (MAX_ROWS - 1); i < MAX_COLS * MAX_ROWS;
             i++) {
            VIDEO_ADDRESS[i] = vga_entry(' ', BLACK, BLACK);
        }
        cursor.y = MAX_ROWS - 1;
    }
    cursor_update(cursor, MAX_ROWS);
}

void tty_clear(void) {
    for (size_t i = 0; i < MAX_COLS * MAX_ROWS; i++) {
        VIDEO_ADDRESS[i] = vga_entry(' ', BLACK, BLACK);
    }
    cursor.x = cursor.y = 0;
    cursor_update(cursor, MAX_ROWS);
}
