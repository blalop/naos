#pragma once

#include "types.h"

// Descriptor tables (GDT, IDT)
// see
// https://web.archive.org/web/20160327011227/http://www.jamesmolloy.co.uk/tutorial_html/4.-The%20GDT%20and%20IDT.html

typedef struct gdt_entry_ {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed)) gdt_entry_t;

typedef struct gdt_ptr_ {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) gdt_ptr_t;

typedef struct idt_entry_ {
    uint16_t base_lo;
    uint16_t sel;
    uint8_t always0;
    uint8_t flags;
    uint16_t base_hi;
} __attribute__((packed)) idt_entry_t;

typedef struct idt_ptr_ {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idt_ptr_t;

void dt_init(void);
