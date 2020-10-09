CC = bin/i686-elf-gcc
AS = bin/i686-elf-as
PREFIX = $(shell pwd)
TARGET = i686-elf
BINUTILS_VERSION = 2.32
GCC_VERSION = 8.3.0

.PHONY: toolchain
toolchain: $(AS) $(CC)

$(AS):
	curl https://ftp.gnu.org/gnu/binutils/binutils-$(BINUTILS_VERSION).tar.gz | tar -xz; \
	mkdir build-binutils-$(BINUTILS_VERSION) && cd build-binutils-$(BINUTILS_VERSION); \
	../binutils-$(BINUTILS_VERSION)/configure --target=$(TARGET) --prefix=$(PREFIX) --with-sysroot --disable-nls --disable-werror; \
	$(MAKE) && $(MAKE) install; \
	cd .. && rm -rf binutils-$(BINUTILS_VERSION) build-binutils-$(BINUTILS_VERSION)

$(CC): $(AS)
	curl https://ftp.gnu.org/gnu/gcc/gcc-$(GCC_VERSION)/gcc-$(GCC_VERSION).tar.gz | tar -xz; \
	mkdir build-gcc-$(GCC_VERSION) && cd build-gcc-$(GCC_VERSION); \
	../gcc-$(GCC_VERSION)/configure --target=$(TARGET) --prefix=$(PREFIX) --disable-nls --enable-languages=c --without-headers; \
	$(MAKE) all-gcc && $(MAKE) all-target-libgcc && $(MAKE) install-gcc && $(MAKE) install-target-libgcc; \
	cd .. && rm -rf gcc-$(GCC_VERSION) build-gcc-$(GCC_VERSION)

.PHONY: clean
clean:
	rm -rf bin $(TARGET) include lib libexec share
