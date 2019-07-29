# naos

naos is my personal attempt for making some systems programming. Just for fun.


## OS Features
* Not POSIX compliant (although inspired, so several functions from the standard lib may resemble POSIX)
* As simple as possible (so assumptions will be made)

## OS Structure
All the code that interacts directly with the hardware resides in `kernel`. The subdirectory `arch/i686` contains the routines specific to x86.

There is a standard library in `libc` directory. It will increase in time.

## OS Roadmap
- [x] Boot in assembly
- [x] Call C
- [x] Print something
- [ ] Interrupts
- [ ] Keyboard
- [ ] Shell
- [ ] FP support
- [ ] Memory management
- [ ] Text editor?

## Building
A build system for the i686-elf cross compiler is included and needed for building the project. Just run `make tools`. It may take a time.

After that, just run `make` to build the kernel image and run it in qemu (or just run `make run`).

### Dependencies
Just qemu and the dependencies needed for building the cross compiler:
* gcc
* make
* bison
* flex
* gmp
* mpc
* mpfr
* texinfo

More info about that at [OsDev wiki](https://wiki.osdev.org/GCC_Cross-Compiler#Installing_Dependencies)

## References
* [The great OsDev wiki](https://wiki.osdev.org)
* [This tutorial from cfenollosa](https://github.com/cfenollosa/os-tutorial)
* [The little book about OS development](https://littleosbook.github.io/)
* [JamesM's tutorial](https://web.archive.org/web/20160412174753/http://www.jamesmolloy.co.uk/tutorial_html/index.html)
* Glibc source code
* Some Tanembaum books
