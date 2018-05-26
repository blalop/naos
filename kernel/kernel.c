#include "../drivers/screen.h"

#if defined(__linux__) || !defined(__i686__)
#error "The compiler is not cross-compiler"
#endif
 
void main() {
    clear_screen();
    kprint("\nKernel loaded\n\n");
    kprint("Welcome");
    return;
}
