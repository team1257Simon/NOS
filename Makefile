all:
	export PATH="~/opt/cross/bin:~/Documents/nasm-2.10.07:${PATH}"
	if [ ! -d Bin ]; 
	then \
		mkdir Bin ; \
	mkdir Bin/Obj ; \
	mkdir Bin/Obj/Kernel ; \
	mkdir Bin/Boot ; \
	mkdir Bin/Kernel ; \
	fi ;
	~/opt/cross/bin/i586-elf-as Kernel/boot.s -o Bin/Obj/Kernel/boot.o
	~/opt/cross/bin/i586-elf-gcc -c Kernel/kernel.c -o Bin/Obj/Kernel/kernel.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
	~/opt/cross/bin/i586-elf-gcc -c KbGdtIdt.c -o Bin/Obj/KbGdtIdt.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
	~/opt/cross/bin/i586-elf-gcc -c Ncio.c -o Bin/Obj/Ncio.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
	~/opt/cross/bin/i586-elf-gcc -T lkern.ld -o Bin/Kernel/Kernel.bin -ffreestanding -O2 -nostdlib Bin/Obj/KbGdtIDt.o Bin/Obj/Ncio.o Bin/Obj/Kernel/boot.o Bin/Obj/Kernel/kernel.o -lgcc	
	~/Documents/nasm-2.10.07/nasm -fbin Boot/St1.s Bin/Obj/Boot/St1.bin
	~/opt/cross/bin/i586-elf-gcc -c Boot/St2.c -o Bin/Obj/Boot/St2.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
	~/opt/cross/bin/i586-elf-gcc -c KbGdtIdt.c -o Bin/Obj/KbGdtIdt.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
	~/opt/cross/bin/i586-elf-gcc -c Ncio.c -o Bin/Obj/Ncio.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
	~/opt/cross/bin/i586-elf-gcc -T Lboot.ld -o Bin/Boot/St2.bin ffreestanding -O2 -nostdlib Bin/Obj/KbGdtIdt.o Bin/Obj/Ncio.o Bin/Obj/Boot/St2.o -lgcc
	
