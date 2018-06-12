#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include "../../arch/i686/vga.h"

void kprint(const char *message);
void kprint_size(const char *message, size_t size);
void kprint_at(const char character, size_t col, size_t row, vgacolor_t charcolor, vgacolor_t backcolor);
void clear_screen(void);

#endif
