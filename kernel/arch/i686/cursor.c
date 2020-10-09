#include "cursor.h"
#include "ports.h"


size_t cursor_offset(cursor_t cursor, size_t width) {
    return cursor.x + cursor.y * width;
}

void cursor_update(cursor_t cursor, size_t width) {
    uint16_t offset = cursor.y * width + cursor.x;
    port_byte_write(0x3D4, 14);
    port_byte_write(0x3D5, offset >> 8);
    port_byte_write(0x3D4, 15);
    port_byte_write(0x3D5, offset);
}
