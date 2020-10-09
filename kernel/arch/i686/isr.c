#include "isr.h"

#include "routines.h"
#include "tty.h"

char *interrupt_messages[] = {"Division By Zero",
                              "Debug",
                              "Non Maskable Interrupt",
                              "Breakpoint",
                              "Into Detected Overflow",
                              "Out of Bounds",
                              "Invalid Opcode",
                              "No Coprocessor",
                              "Double Fault",
                              "Coprocessor Segment Overrun",
                              "Bad TSS",
                              "Segment Not Present",
                              "Stack Fault",
                              "General Protection Fault",
                              "Page Fault",
                              "Unknown Interrupt",
                              "Coprocessor Fault",
                              "Alignment Check",
                              "Machine Check",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved"};

void isr_handler(registers_t reg) {
    char interrupt_code[3];
    routines_int_to_ascii(reg.int_no, interrupt_code);
    tty_prints("\nISR: Interrupt received: ");
    tty_prints(interrupt_code);
    tty_prints(" - ");
    tty_prints(interrupt_messages[reg.int_no]);
}
