#pragma once

#include "types.h"

// x86 I/O ports
// https://wiki.osdev.org/I/O_Ports

static const uint16_t REG_SCREEN_CTRL = 0x3D4;
static const uint16_t REG_SCREEN_DATA = 0x3D5;

uint8_t port_byte_read(uint16_t port);

void port_byte_write(uint16_t port, uint8_t data);

uint16_t port_word_read(uint16_t port);

void port_word_write(uint16_t port, uint16_t data);
