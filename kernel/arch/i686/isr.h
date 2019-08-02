/**
 * @file
 * @brief Interrupt services routines.
 *
 * Contains the interrupt handler.
 * @see https://github.com/cfenollosa/os-tutorial/tree/master/18-interrupts
 * @see
 * https://web.archive.org/web/20160327011227/http://www.jamesmolloy.co.uk/tutorial_html/4.-The%20GDT%20and%20IDT.html
 */

#ifndef KERNEL_ISR_H
#define KERNEL_ISR_H

#include <stdint.h>

/** Register structure */
typedef struct registers {
    uint32_t ds;                                      //!< Data segment selector
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;  //!< Pushed by pusha
    uint32_t int_no, err_code;                        //!< number and error code
    uint32_t eip, cs, eflags, useresp, ss;  //!< Pushed by the processor
} registers_t;

/**
 * Interrupt handler
 *
 * @param reg Register (passed automatically)
 */
void isr_handler(registers_t reg);

#endif  // KERNEL_ISR_H
