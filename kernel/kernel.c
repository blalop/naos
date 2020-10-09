#if !defined(__i686__)
#error The compiler is not cross-compiler!
#endif

#include "arch/i686/dt.h"
#include "arch/i686/tty.h"

void kinit(void) {
    dt_init();
    tty_clear();

    tty_prints("Welcome\n\n");
    asm volatile("int $3");
    asm volatile("int $3");
}

void kloop(void) {}

void kmain(void) {
    kinit();
    while (1) {
        kloop();
    }
}
