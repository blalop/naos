CC = toolchain/bin/i686-elf-gcc
AS = toolchain/bin/i686-elf-as
CFLAGS = -std=gnu11 -Wall -Wextra -fdiagnostics-color=always -fno-pie -ffreestanding -nostdlib -Ilibc
SOURCES = $(wildcard kernel/*.c kernel/arch/i686/*.c libc/*.c)
ASM_SOURCES = $(wildcard kernel/arch/i686/*.s)
HEADERS = $(wildcard kernel/*.h kernel/arch/i686/*.h libc/*.h)
OBJECTS = $(SOURCES:.c=.o) $(ASM_SOURCES:.s=.o)

.PHONY: all
all: naos.bin

.PHONY: run
run: naos.bin
	qemu-system-i386 -kernel naos.bin

# Main project
naos.bin: $(OBJECTS)
	$(CC) -T linker.ld -o $@ $(CFLAGS) $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(AS) $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJECTS) naos.bin
