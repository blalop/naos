#include "screen.h"
#include "ports.h"

int get_cursor_offset();
void set_cursor_offset(int offset);
int print_char(char character, int col, int row, char attr);
int get_offset(int col, int row);
int get_offset_row(int offset);
int get_offset_col(int offset);

void kprint(char *message) {
    kprint_at(message, -1, -1);
}

void kprintc(char *message, char charcolor, char backcolor) {
    kprintc_at(message, -1, -1, charcolor, backcolor);
}

void kprint_at(char *message, int col, int row) {
    kprintc_at(message, col, row, WHITE, BLACK);
}

void kprintc_at(char *message, int col, int row, char charcolor, char backcolor) {
    int offset;

    if (col >= 0 && row >= 0) {
        offset = get_offset(col, row);
    } else {
        offset = get_cursor_offset();
        row = get_offset_row(offset);
        col = get_offset_col(offset);
    }

    for (int i = 0; message[i] != 0; i++) {
        offset = print_char(message[i], col, row, COLOR_CALC(charcolor, backcolor));
        row = get_offset_row(offset);
        col = get_offset_col(offset);
    }
}

void clear_screen() {
    unsigned char *vidaddr = (unsigned char*) VIDEO_ADDRESS;

    for (int i = 0; i < MAX_COLS * MAX_ROWS; i++) {
        vidaddr[i * 2] = ' ';
        vidaddr[i * 2 + 1] = COLOR_CALC(WHITE, BLACK);
    }
    set_cursor_offset(get_offset(0, 0));
}


// private
int print_char(char c, int col, int row, char attr) {
    unsigned char *vidaddr = (unsigned char*) VIDEO_ADDRESS;
    
    // default attr
    if (!attr) attr =  COLOR_CALC(WHITE, BLACK);

    // error control
    if (col >= MAX_COLS || row >= MAX_ROWS) {
        vidaddr[2*(MAX_COLS)*(MAX_ROWS)-2] = 'E';
        vidaddr[2*(MAX_COLS)*(MAX_ROWS)-1] = COLOR_CALC(RED, WHITE);
        return get_offset(col, row);
    }

    int offset;
    if (col >= 0 && row >= 0) offset = get_offset(col, row);
    else offset = get_cursor_offset();

    if (c == '\n') {
        row = get_offset_row(offset);
        offset = get_offset(0, row + 1);
    } else {
        vidaddr[offset] = c;
        vidaddr[offset+1] = attr;
        offset += 2;
    }
    set_cursor_offset(offset);
    return offset;
}

int get_cursor_offset() {
    port_byte_out(REG_SCREEN_CTRL, 14);
    int offset = port_byte_in(REG_SCREEN_DATA) << 8;
    port_byte_out(REG_SCREEN_CTRL, 15);
    offset += port_byte_in(REG_SCREEN_DATA);
    return offset * 2;
}

void set_cursor_offset(int offset) {
    offset /= 2;
    port_byte_out(REG_SCREEN_CTRL, 14);
    port_byte_out(REG_SCREEN_DATA, (unsigned char)(offset >> 8));
    port_byte_out(REG_SCREEN_CTRL, 15);
    port_byte_out(REG_SCREEN_DATA, (unsigned char)(offset & 0xff));
}


int get_offset(int col, int row) {
    return 2 * (row * MAX_COLS + col);
}

int get_offset_row(int offset) {
    return offset / (2 * MAX_COLS);
}

int get_offset_col(int offset) {
    return (offset - (get_offset_row(offset) * 2 * MAX_COLS)) / 2;
}
