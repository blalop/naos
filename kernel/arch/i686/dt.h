/**
 * @file
 * @brief GDT.
 *
 * @see https://wiki.osdev.org/GDT_Tutorial
 * @see
 * https://web.archive.org/web/20160327011227/http://www.jamesmolloy.co.uk/tutorial_html/4.-The%20GDT%20and%20IDT.html
 */

#ifndef KERNEL_DT_H
#define KERNEL_DT_H

#include <stdint.h>

/** GDT entry structure */
typedef struct gdt_entry_ {
    uint16_t limit_low;   //!< The lower 16 bits of the limit.
    uint16_t base_low;    //!< The lower 16 bits of the base.
    uint8_t base_middle;  //!< The next 8 bits of the base.
    uint8_t access;       //!< Access flags, determine ring
    uint8_t granularity;
    uint8_t base_high;  //!< The last 8 bits of the base.
} __attribute__((packed)) gdt_entry_t;

/** GDT table pointer */
typedef struct gdt_ptr_ {
    uint16_t limit;  //!< The upper 16 bits of all selector limits.
    uint32_t base;   //!< The address of the first gdt_entry_t struct.
} __attribute__((packed)) gdt_ptr_t;

/** IDT entry structure */
typedef struct idt_entry_ {
    uint16_t base_lo;  //!< The lower 16 bits of the address to jump
    uint16_t sel;      //!< Kernel segment selector.
    uint8_t always0;   //!< This must always be zero.
    uint8_t flags;     //!< More flags. See documentation.
    uint16_t base_hi;  //!< The upper 16 bits of the address to jump to.
} __attribute__((packed)) idt_entry_t;

/** Pointer to an array of interrupt handlers. */
typedef struct idt_ptr_ {
    uint16_t limit;
    uint32_t base;  //!< The address of the first element in idt_entry_t array.
} __attribute__((packed)) idt_ptr_t;

/** Initializes the GDT and the IDT */
void dt_init(void);

#endif  // KERNEL_DT_H
