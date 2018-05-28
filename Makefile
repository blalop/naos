CC = i686-elf-gcc
LD = i686-elf-ld
AS = nasm
CFLAGS = -Wall -Wextra -fno-pie -ffreestanding -nostdlib
SOURCES = $(wildcard kernel/*.c kernel/arch/i686/*.c libc/*.c)
HEADERS = $(wildcard kernel/*.h kernel/arch/i686/*.h libc/*.h)
OBJECTS = $(SOURCES:.c=.o)

all: naos

run: naos
	qemu-system-x86_64 -kernel naos

naos: kernel/arch/i686/boot.o $(OBJECTS)
	$(CC) -T linker.ld -o $@ $(CFLAGS) $^ 

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.asm
	$(AS) $< -f elf -o $@

%.bin: %.asm
	$(AS) $< -f bin -o $@

.PHONY: clean
clean:
	rm -rf *.bin *.dis *.o naos
	rm -rf libc/*.o kernel/*.o drivers/*.o boot/*.o boot/*.bin
