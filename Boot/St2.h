#include "../Gdt.h"
#include "../Idt.h"
#include "../Keyboard.h"
#include "../irq.h"
extern void stage2_main();
unsigned int irq_mask = 0xffff;
desc_table{IDT,256){};
desc_table(GDT,3){};
