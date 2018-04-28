run: boot.bin
	qemu-system-x86_64 boot.bin 

boot.bin: boot.s gdt.s pm.s print.s
	nasm boot.s -f bin -o boot.bin

.PHONY: clean
clean:
	rm boot.bin
