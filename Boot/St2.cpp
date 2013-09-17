#include "../KbGdtIdt.h"
inline void ea20()
{
 __asm__ volatile ("mov $0x2401h,%ax\n"
"int 15");
}
extern void startKernel();
__asm__(
".globl startKernel\n"
"startKernel:\n"
"cli \n"
"extrn _start:0x1000000\n"
"mov %cr0,%eax\n"
"or $1,%eax\n"
"mov %eax,%cr0\n"
"mov $0x10h,%ax\n"
"mov %ax,%ds\n"
"mov %ax,%es\n"
"mov %ax,%fs\n"
"mov %ax,%gs\n"
"mov %ax,%ss\n"
"call _start\n"
".qqq:\n"
"jmp .qqq"
);
extern void stage2main()
{
 InitGdt();
 InitIdt();
 Init8259();
 InitKeyboard();
 startKernel();
}
