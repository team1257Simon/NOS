#define _ST2_C
#define _KSTAT_CURR
#include "../KbGdtIdt.h"
/*inline void ea20()
{
<<<<<<< HEAD
 __asm__ volatile ("mov $1,%al\n"
"out %al,0x92");
=======
 __asm__ volatile ("mov $0x2401,%ax\n"
"int 0x15");
>>>>>>> branch 'master' of https://github.com/team1257Simon/NOS.git
}*/
extern void startKernel();
__asm__(
".globl startKernel\n"
"startKernel:\n"
"cli \n"
"mov %cr0,%eax\n"
"or $1,%eax\n"
"mov %eax,%cr0\n"
"mov $0x10,%ax\n"
"mov %ax,%ds\n"
"mov %ax,%es\n"
"mov %ax,%fs\n"
"mov %ax,%gs\n"
"mov %ax,%ss\n"
"jmp 0x1000000\n"
".qqq:\n"
"jmp .qqq"
);
extern void _stage2_main()
{
 InitGDT();
 InitIDT();
 Init8259();
 InitKeyboard();
 //ea20();
 startKernel();
}
