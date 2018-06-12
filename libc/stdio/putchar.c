#include <stdio.h>
#include <tty.h>

int putchar(int character) {
	char c = (char) character;
	kprint(&c);
	return character;
}
