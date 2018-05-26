#ifndef NAOS_SCREEN_H
#define NAOS_SCREEN_H

#include "../kernel/common.h"

#define MAX_ROWS 25
#define MAX_COLS 80

static uint16_t * const VIDEO_ADDRESS = (uint16_t*) 0xB8000;

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

void kprint(char *message);
void kprint_at(char c, size_t col, size_t row, vgacolor_t charcolor, vgacolor_t backcolor);
void clear_screen();

#endif
