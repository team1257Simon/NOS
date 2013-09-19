#ifndef _ALL_H
#define _ALL_H
#include "Gdt.h"
#include "Idt.h"
#include "Keyboard.h"
#include "ncio.h"
#include "irq.h"
extern void stage2_main();
#ifndef _ST2_C
unsigned int irq_mask = 0xffff;
desc_table(IDT,256){};
desc_table(GDT,3){
{dummy:0}
};
#endif
#endif
