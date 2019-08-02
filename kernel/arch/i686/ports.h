/**
 * @file
 * @brief x86 I/O ports.
 *
 * An I/O port is an specific address on the IO bus. Communication with devices
 * is made by reading and writing this specific address.
 *
 * @see https://wiki.osdev.org/I/O_Ports
 */

#ifndef KERNEL_PORTS_H
#define KERNEL_PORTS_H

#include <stdint.h>

static const uint16_t REG_SCREEN_CTRL = 0x3D4;  //!< Cursor input
static const uint16_t REG_SCREEN_DATA = 0x3D5;  //!< Cursor output

/**
 * Reads a byte for the specified port
 *
 * @param port The port to be readed
 */
uint8_t port_byte_read(uint16_t port);

/**
 * Writes a byte in the specified port
 *
 * @param port The port to be written
 * @param data The byte to be written
 */
void port_byte_write(uint16_t port, uint8_t data);

/**
 * Read a word for the specified port
 *
 * @param port The port to be read
 */
uint16_t port_word_read(uint16_t port);

/**
 * Writes a word in the specified port
 *
 * @param port The port to be written
 * @param data The word to be written
 */
void port_word_write(uint16_t port, uint16_t data);

#endif  // KERNEL_PORTS_H
