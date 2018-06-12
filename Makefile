CC = i686-linux-gnu-gcc
LD = i686-linux-gnu-ld
AS = nasm
CFLAGS = -Wall -Wextra -fno-pie -ffreestanding -nostdlib -Ilibc/include -Ikernel/include
SOURCES = $(wildcard kernel/*.c arch/i686/*.c libc/*/*.c)
HEADERS = $(wildcard kernel/*.h arch/i686/*.h libc/*.h)
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all
all: naos

.PHONY: run
run: naos
	qemu-system-i386 -kernel naos

naos: arch/i686/boot.o $(OBJECTS)
	$(CC) -T linker.ld -o $@ $(CFLAGS) $^ 

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.asm
	$(AS) $< -f elf -o $@

.PHONY: clean
clean:
	rm -f *.o naos
	rm -f libc/*/*.o kernel/*.o drivers/*.o arch/i686/*.o
