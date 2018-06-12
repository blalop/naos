#include <stdio.h>
#include <tty.h>

int puts(const char *str) {
	kprint(str);
    kprint("\n");
    return 0;
}