#if !defined(__i686__)
#error The compiler is not cross-compiler!
#endif

#include <stdio.h>

#include "arch/i686/dt.h"

void kinit(void) {
    dt_init();
    clearscreen();

    printf("Welcome %d\n\n", 1);
    asm volatile("int $2");
}

void kloop(void) {}

void kmain(void) {
    kinit();
    while (1) {
        kloop();
    }
}
