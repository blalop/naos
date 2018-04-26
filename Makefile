run: boot.bin
	qemu-system-x86_64 boot.bin 

boot.bin: boot.asm
	nasm boot.asm -f bin -o boot.bin

.PHONY : clean
clean:
	rm boot.bin
