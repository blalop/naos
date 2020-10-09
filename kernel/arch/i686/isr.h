#pragma once

#include "types.h"

// Interrupt services routines.
// https://github.com/cfenollosa/os-tutorial/tree/master/18-interrupts
// https://web.archive.org/web/20160327011227/http://www.jamesmolloy.co.uk/tutorial_html/4.-The%20GDT%20and%20IDT.html

typedef struct registers {
    uint32_t ds;                                      // Data segment selector
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;  // Pushed by pusha
    uint32_t int_no, err_code;                        // number and error code
    uint32_t eip, cs, eflags, useresp, ss;            // Pushed by the processor
} registers_t;

void isr_handler(registers_t reg);
