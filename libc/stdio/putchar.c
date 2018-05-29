#include <stdio.h>
#include "../../arch/i686/vga.h"

int putchar(int character) {
	char c = (char) character;
	kprint(&c);
	return character;
}
