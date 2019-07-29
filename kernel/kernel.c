
#if !defined(__i686__)
#error The compiler is not cross-compiler!
#endif

#include "arch/i686/tty.h"
#include "stdio.h"

void kmain(void) {
    tty_clear_screen();
    printf("\nWelcome\n");
    while (1);
}
