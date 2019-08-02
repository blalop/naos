#include "ports.h"

uint8_t port_byte_read(uint16_t port) {
    uint8_t result;
    asm("in %%dx, %%al" : "=a"(result) : "d"(port));
    return result;
}

void port_byte_write(uint16_t port, uint8_t data) {
    asm volatile("out %%al, %%dx" : : "a"(data), "d"(port));
}

uint16_t port_word_read(uint16_t port) {
    uint16_t result;
    asm("in %%dx, %%ax" : "=a"(result) : "d"(port));
    return result;
}

void port_word_write(uint16_t port, uint16_t data) {
    asm volatile("out %%ax, %%dx" : : "a"(data), "d"(port));
}
