PATH="/usr/cross:$PATH"
All:
i586-elf-as Kernel/boot.s -o Bin/Obj/boot.o
i586-elf-g++ -c Kernel/kernel.cpp -o Bin/Obj/kernel.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
i586-elf-gcc -T linker.ld -o Bin/myos.bin -ffreestanding -O2 -nostdlib Bin/Obj/boot.o Bin/Obj/kernel.o -lgcc
Test:
i586-elf-as Kernel/boot.s -o Bin/Obj/boot.o
i586-elf-g++ -c Kernel/kernel.cpp -o Bin/Obj/kernel.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
i586-elf-gcc -T linker.ld -o Bin/myos.bin -ffreestanding -O2 -nostdlib Bin/Obj/boot.o Bin/Obj/kernel.o -lgcc
qemu-system-i386 -kernel Bin/myos.bin
