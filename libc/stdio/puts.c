#include <stdio.h>
#include "../../arch/i686/vga.h"

int puts(const char *str) {
	kprint(str);
    kprint("\n");
    return 0;
}