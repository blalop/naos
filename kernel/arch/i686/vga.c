#include "ports.h"
#include "vga.h"

static void put_char(char c);
static void update_cursor();
static inline size_t get_cursor();

static volatile size_t cursor_x;
static volatile size_t cursor_y;

void kprint(char *message) {
    size_t i = 0;
    while (message[i] != 0) {
        put_char(message[i++]);
    }
}

void kprint_at(char c, size_t col, size_t row, vgacolor_t charcolor, vgacolor_t backcolor) {
    if (col < MAX_COLS && row < MAX_ROWS) { 
        VIDEO_ADDRESS[col + MAX_COLS * row] = vga_entry(c, vga_entry_color(charcolor, backcolor));
    }
}

void clear_screen() {
    for (size_t i = 0; i < MAX_COLS * MAX_ROWS; i++) {
        VIDEO_ADDRESS[i] = vga_entry(' ', 0);
    }
    cursor_x = cursor_y = 0;
    update_cursor();
}

// private
void put_char(char c) {
    // check char
    switch (c) {
        case '\b':
            if (cursor_x > 0) {
                cursor_x--;
            }
            break;
        case '\n':
            cursor_x = 0;
            cursor_y++;
            break;
        case '\r':
            cursor_x = 0;
            break;
        case '\t':
            cursor_x = (cursor_x + 8) & ~(8 - 1);
            break;
        case ' ' ... '~':
            VIDEO_ADDRESS[get_cursor()] = vga_entry(c, vga_entry_color(LIGHT_GRAY, BLACK));
            cursor_x++;
            break;
    }

    // new line
    if (cursor_x >= MAX_COLS) {
        cursor_x = 0;
        cursor_y++;
    }

    // scroll
    if (cursor_y >= MAX_ROWS) {
        for (size_t i = 0; i < MAX_COLS * (MAX_ROWS - 1); i++) {
            VIDEO_ADDRESS[i] = VIDEO_ADDRESS[i + MAX_COLS];
        }
        for (size_t i = MAX_COLS * (MAX_ROWS - 1); i < MAX_COLS * MAX_ROWS; i++) {
            VIDEO_ADDRESS[i] = vga_entry(' ', 0);
        }
        cursor_y = MAX_ROWS - 1;
    }
    update_cursor();
}

void update_cursor() {
    size_t cursor = get_cursor();
    port_byte_out(REG_SCREEN_CTRL, 14);
    port_byte_out(REG_SCREEN_DATA, cursor >> 8);
    port_byte_out(REG_SCREEN_CTRL, 15);
    port_byte_out(REG_SCREEN_DATA, cursor);
}

size_t get_cursor() {
    return cursor_x + cursor_y * MAX_COLS;
}