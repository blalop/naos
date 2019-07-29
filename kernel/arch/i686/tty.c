
#include "tty.h"
#include "ports.h"

#include <stdint.h>

// Cursor structure declaration
typedef struct cursor_ {
    size_t x;
    size_t y;
} cursor_t;

// TTY values: size, memory addr and cursor
static const size_t MAX_ROWS = 25;
static const size_t MAX_COLS = 80;
static uint16_t *const VIDEO_ADDRESS = (uint16_t *)0xB8000;
static volatile cursor_t cursor;

// Helper functions
static inline size_t get_cursor(void) { return cursor.x + cursor.y * MAX_COLS; }

static void update_cursor(void) {
    size_t cursor_pos = get_cursor();
    port_byte_out(REG_SCREEN_CTRL, 14);
    port_byte_out(REG_SCREEN_DATA, cursor_pos >> 8);
    port_byte_out(REG_SCREEN_CTRL, 15);
    port_byte_out(REG_SCREEN_DATA, cursor_pos);
}

static inline uint16_t vga_entry(char c, vgacolor_t fg, vgacolor_t bg) {
    uint8_t color = bg << 4 | fg;
    return color << 8 | c;
}

void tty_kprint_color(char c, vgacolor_t fg, vgacolor_t bg) {
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
        VIDEO_ADDRESS[get_cursor()] = vga_entry(c, fg, bg);
        cursor.x++;
        break;
    }

    if (cursor.x >= MAX_COLS) { // new line
        cursor.x = 0;
        cursor.y++;
    }

    if (cursor.y >= MAX_ROWS) { // scroll
        for (size_t i = 0; i < MAX_COLS * (MAX_ROWS - 1); i++) {
            VIDEO_ADDRESS[i] = VIDEO_ADDRESS[i + MAX_COLS];
        }
        for (size_t i = MAX_COLS * (MAX_ROWS - 1); i < MAX_COLS * MAX_ROWS;
             i++) {
            VIDEO_ADDRESS[i] = vga_entry(' ', BLACK, BLACK);
        }
        cursor.y = MAX_ROWS - 1;
    }
    update_cursor();
}

void tty_kprint(char c) { tty_kprint_color(c, LIGHT_GRAY, BLACK); }

void tty_kdraw(char c, size_t col, size_t row, vgacolor_t fg, vgacolor_t bg) {
    if (col < MAX_COLS && row < MAX_ROWS) {
        VIDEO_ADDRESS[col + MAX_COLS * row] = vga_entry(c, fg, bg);
    }
}

void tty_clear_screen(void) {
    for (size_t i = 0; i < MAX_COLS * MAX_ROWS; i++) {
        VIDEO_ADDRESS[i] = vga_entry(' ', BLACK, BLACK);
    }
    cursor.x = cursor.y = 0;
    update_cursor();
}
