#ifndef NAOS_VGA_H
#define NAOS_VGA_H

#include <stddef.h>
#include <stdint.h>

#define MAX_ROWS 25
#define MAX_COLS 80

static uint16_t * const VIDEO_ADDRESS = (uint16_t*)  0xB8000;

typedef enum {
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

static inline uint16_t vga_entry(const char c, uint8_t color) {
	return color << 8 | c;
}

static inline uint8_t vga_entry_color(vgacolor_t fg, vgacolor_t bg) {
	return bg << 4 | fg;
}

#endif
