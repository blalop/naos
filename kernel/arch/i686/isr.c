#include "isr.h"

#include <stdio.h>

void isr_handler(registers_t reg) {
    printf("Recieved interrupt: %d\n", reg.int_no);
}
