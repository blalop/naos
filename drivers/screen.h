#ifndef SCREEN_H
#define SCREEN_H

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80

// Attributes
#define BLACK 0x0
#define BLUE 0x1
#define GREEN 0x2
#define CYAN 0x3
#define RED 0x4
#define MAGENTA 0x5
#define BROWN 0x6
#define LIGHT_GRAY 0x7
#define DARK_GRAY 0x8
#define LIGHT_BLUE 0x9
#define LIGHT_GREEN 0xA
#define LIGHT_CYAN 0xB
#define LIGHT_RED 0xC
#define LIGHT_MAGENTA 0xD
#define LIGHT_YELLOW 0xE
#define WHITE 0xF

#define COLOR_CALC(character, background) ((background << 4) | character)

// Ports
#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5

// Kernel screen functions
void kprint(char *message);
void kprint_at(char *message, int col, int row);
void kprintc(char *message, char charcolor, char backcolor);
void kprintc_at(char *message, int col, int row, char charcolor, char backcolor);
void clear_screen();

#endif
