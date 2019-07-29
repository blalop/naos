CC = tools/bin/i686-elf-gcc
AS = tools/bin/i686-elf-as
CFLAGS = -std=gnu11 -Wall -Wextra -fdiagnostics-color=always -fno-pie -ffreestanding -nostdlib -Ilibc
SOURCES = $(wildcard kernel/*.c kernel/arch/i686/*.c libc/*.c)
HEADERS = $(wildcard kernel/*.h kernel/arch/i686/*.h libc/*.h)
OBJECTS = $(SOURCES:.c=.o) kernel/arch/i686/boot.o

.PHONY: tools all
all: naos.bin

.PHONY: run
run: naos.bin
	qemu-system-i386 -kernel naos.bin

naos.bin: $(OBJECTS)
	$(CC) -T linker.ld -o $@ $(CFLAGS) $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(AS) $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJECTS) naos.bin

# Cross compiler and binutils
PREFIX = $(shell pwd)/tools
TARGET = i686-elf
BINUTILS_VERSION = 2.32
GCC_VERSION = 8.3.0

.PHONY: tools
tools: $(AS) $(CC)

$(AS):
	mkdir -p tools && cd tools; \
	curl https://ftp.gnu.org/gnu/binutils/binutils-$(BINUTILS_VERSION).tar.gz | tar -xz; \
	mkdir build-binutils-$(BINUTILS_VERSION) && cd build-binutils-$(BINUTILS_VERSION); \
	../binutils-$(BINUTILS_VERSION)/configure --target=$(TARGET) --prefix=$(PREFIX) --with-sysroot --disable-nls --disable-werror; \
	$(MAKE) && $(MAKE) install; \
	cd .. && rm -rf binutils-$(BINUTILS_VERSION) build-binutils-$(BINUTILS_VERSION)

$(CC): $(AS)
	mkdir -p tools && cd tools; \
	curl https://ftp.gnu.org/gnu/gcc/gcc-$(GCC_VERSION)/gcc-$(GCC_VERSION).tar.gz | tar -xz; \
	mkdir build-gcc-$(GCC_VERSION) && cd build-gcc-$(GCC_VERSION); \
	../gcc-$(GCC_VERSION)/configure --target=$(TARGET) --prefix=$(PREFIX) --disable-nls --enable-languages=c --without-headers; \
	$(MAKE) all-gcc && $(MAKE) all-target-libgcc && $(MAKE) install-gcc && $(MAKE) install-target-libgcc; \
	cd .. && rm -rf gcc-$(GCC_VERSION) build-gcc-$(GCC_VERSION)

.PHONY: cleantools
cleantools:
	rm -rf tools
