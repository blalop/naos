run: naos
	qemu-system-x86_64 -drive format=raw,if=floppy,file=naos

naos: boot.bin kernel.bin
	cat boot.bin kernel.bin > naos

boot.bin: boot.s gdt.s pm.s print.s disk.s
	nasm boot.s -f bin -o boot.bin

kernel.bin: kernel.c
	gcc -ffreestanding -c kernel.c -o kernel.o
	ld -o kernel.bin -Ttext 0x1000 kernel.o --oformat binary

.PHONY: clean
clean:
	rm *.bin *.o
