CC = i686-elf-gcc
LD = i686-elf-ld
AS = nasm
CFLAGS = -Wall -Wextra -fno-pie -ffreestanding
SOURCES = $(wildcard kernel/*.c drivers/*.c lib/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h lib/*.c)
OBJ = $(SOURCES:.c=.o)

all: naos

run: naos
	qemu-system-x86_64 -drive format=raw,if=floppy,file=naos

naos: boot/boot.bin kernel.bin
	cat $^ > $@

kernel.bin: boot/kernel_call.o $(OBJ)
	$(LD) -o $@ -Ttext 0x1000 $^ --oformat binary -nostdlib

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.asm
	$(AS) $< -f elf -o $@

%.bin: %.asm
	$(AS) $< -f bin -o $@

.PHONY: clean
clean:
	rm -rf *.bin *.dis *.o naos
	rm -rf lib/*.o kernel/*.o drivers/*.o boot/*.o boot/*.bin
