
#if !defined(__i686__)
#error The compiler is not cross-compiler!
#endif

#include <stdio.h>

void kmain(void) {
    clearscreen();
    printf("\nWelcome\n");
    while (1)
        ;
}
