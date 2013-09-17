all:
	export PATH="~/opt/cross/bin:~/Documents/nasm-2.10.07:$PATH"
	mkdir Bin
	mkdir Bin/Obj
	Kernel
	Boot
Kernel:
	mkdir Bin/Kernel
	mkdir Bin/Obj/Kernel
	i586-elf-as Kernel/boot.s -o Bin/Obj/Kernel/boot.o
	i586-elf-g++ -c Kernel/kernel.cpp -o Bin/Obj/Kernel/kernel.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
	i586-elf-gcc -c KbGdtIdt.cpp -o Bin/Obj/KbGdtIdt.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
	i586-elf-gcc -c Ncio.cpp -o Bin/Obj/Ncio.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
	i586-elf-gcc -T lkern.ld -o Bin/Kernel/Kernel.bin -ffreestanding -O2 -nostdlib Bin/Obj/Kernel/boot.o Bin/Obj/Kernel/kernel.o -lgcc
	
Boot:
	mkdir Bin/Boot
	mkdir Bin/Obj/Boot
	nasm -fbin Boot/St1.s Bin/Obj/Boot/St1.o
	i586-elf-gcc -c Boot/St2.cpp -o Bin/Obj/Boot/St2.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
	i586-elf-gcc -c KbGdtIdt.cpp -o Bin/Obj/KbGdtIdt.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
	i586-elf-gcc -c Ncio.cpp -o Bin/Obj/Ncio.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
	i586-elf-gcc -T Lboot.ld -o Bin/Boot/Btloader.bin
	
