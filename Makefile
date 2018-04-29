CC = gcc
CFLAGS = -Wall -Werror -Wfatal-errors -m32 -fno-pie -ffreestanding
SOURCES = $(wildcard kernel/*.c drivers/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h)
OBJ = $(SOURCES:.c=.o)

all: naos

run: naos
	qemu-system-x86_64 -drive format=raw,if=floppy,file=naos

naos: boot/boot.bin kernel.bin
	cat $^ > $@


kernel.bin: boot/kernel_call.o $(OBJ)
	ld -m elf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

kernel.dis: kernel.bin
	ndisasm -b 32 $< > $@

.PHONY: clean
clean:
	rm -rf *.bin *.dis *.o naos
	rm -rf kernel/*.o drivers/*.o boot/*.o boot/*.bin
