/**
 * @file
 * Kernel main file.
 */

#if !defined(__i686__)
#error The compiler is not cross-compiler!
#endif

#include <stdio.h>
#include "arch/i686/dt.h"

/** The kernel initialization function */
void kinit(void) {
    dt_init();
    clearscreen();

    printf("Welcome %d\n\n", 1);
    asm volatile("int $2");
}

/** The kernel main loop */
void kloop(void) {}

/** The kernel main function. */
void kmain(void) {
    kinit();
    while (1) {
        kloop();
    }
}
