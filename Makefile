CC= gcc
CFLAGS = -Wall -Werror -Wfatal-errors -m32 -fno-pie -ffreestanding
SOURCES = (wildcard kernel /*.c drivers /*.c)
OBJ = ${SOURCES :.c=.o}

all: dirs naos

run: naos
	qemu-system-x86_64 -drive format=raw,if=floppy,file=naos

naos: build/boot.bin build/kernel.bin
	cat $^ > $@

build/boot.bin: boot/boot.asm
	nasm boot/boot.asm -f bin -o $@

build/kernel.bin: build/kernel_call.o build/kernel.o
	ld -m elf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

build/kernel_call.o: kernel/kernel_call.asm
	nasm $< -f elf -o $@

build/kernel.o: kernel/kernel.c
	$(CC) $(CFLAGS) -c $< -o $@

kernel.dis: build/kernel.bin
	ndisasm -b 32 $< > $@

.PHONY: dirs
dirs:
	mkdir -p build

.PHONY: clean
clean:
	rm -rf build naos
