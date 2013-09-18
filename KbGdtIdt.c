#include "KbGdtIdt.h"
int kbs=0;
unsigned int scan2ascii_table[][8] = 
{
/*      ASCII - Shift - Ctrl -  Alt -   Num -   Caps -  Shift Caps -    Shift Num */
{       0,      0,      0,      0,      0,      0,      0,              0},
{       0x1B,   0x1B,   0x1B,   0,      0x1B,   0x1B,   0x1B,           0x1B},
/* 1 -> 9 */
{       0x31,   0x21,   0,      0x7800, 0x31,   0x31,   0x21,           0x21},
{       0x32,   0x40,   0x0300, 0x7900, 0x32,   0x32,   0x40,           0x40},
{       0x33,   0x23,   0,      0x7A00, 0x33,   0x33,   0x23,           0x23},
{       0x34,   0x24,   0,      0x7B00, 0x34,   0x34,   0x24,           0x24},
{       0x35,   0x25,   0,      0x7C00, 0x35,   0x35,   0x25,           0x25},
{       0x36,   0x5E,   0x1E,   0x7D00, 0x36,   0x36,   0x5E,           0x5E},
{       0x37,   0x26,   0,      0x7E00, 0x37,   0x37,   0x26,           0x26},
{       0x38,   0x2A,   0,      0x7F00, 0x38,   0x38,   0x2A,           0x2A},
{       0x39,   0x28,   0,      0x8000, 0x39,   0x39,   0x28,           0x28},
{       0x30,   0x29,   0,      0x8100, 0x30,   0x30,   0x29,           0x29},
/* -, =, Bksp, Tab */
{       0x2D,   0x5F,   0x1F,   0x8200, 0x2D,   0x2D,   0x5F,           0x5F},
{       0x3D,   0x2B,   0,      0x8300, 0x3D,   0x3D,   0x2B,           0x2B},
{       0x08,   0x08,   0x7F,   0,      0x08,   0x08,   0x08,           0x08},
{       0x09,   0x0F00, 0,      0,      0x09,   0x09,   0x0F00,         0x0F00},
/*      QWERTYUIOP[] */
{       0x71,   0x51,   0x11,   0x1000, 0x71,   0x51,   0x71,           0x51},
{       0x77,   0x57,   0x17,   0x1100, 0x77,   0x57,   0x77,           0x57},
{       0x65,   0x45,   0x05,   0x1200, 0x65,   0x45,   0x65,           0x45},
{       0x72,   0x52,   0x12,   0x1300, 0x72,   0x52,   0x72,           0x52},
{       0x74,   0x54,   0x14,   0x1400, 0x74,   0x54,   0x74,           0x54},
{       0x79,   0x59,   0x19,   0x1500, 0x79,   0x59,   0x79,           0x59},
{       0x75,   0x55,   0x15,   0x1600, 0x75,   0x55,   0x75,           0x55},
{       0x69,   0x49,   0x09,   0x1700, 0x69,   0x49,   0x69,           0x49},
{       0x6F,   0x4F,   0x0F,   0x1800, 0x6F,   0x4F,   0x6F,           0x4F},
{       0x70,   0x50,   0x10,   0x1900, 0x70,   0x50,   0x70,           0x50},
{       0x5B,   0x7B,   0x1B,   0x0,    0x5B,   0x5B,   0x7B,           0x7B},
{       0x5D,   0x7D,   0x1D,   0,      0x5D,   0x5D,   0x7D,           0x7D},
/* ENTER, CTRL */
{       0x0A,   0x0A,   0x0D,   0,      0x0A,   0x0A,   0x0D,           0x0D},
{       0,      0,      0,      0,      0,      0,      0,              0},
/* ASDFGHJKL;'~ */
{       0x61,   0x41,   0x01,   0x1E00, 0x61,   0x41,   0x61,           0x41},
{       0x73,   0x53,   0x13,   0x1F00, 0x73,   0x53,   0x73,           0x53},
{       0x64,   0x44,   0x04,   0x2000, 0x64,   0x44,   0x64,           0x44},
{       0x66,   0x46,   0x06,   0x2100, 0x66,   0x46,   0x66,           0x46},
{       0x67,   0x47,   0x07,   0x2200, 0x67,   0x47,   0x67,           0x47},
{       0x68,   0x48,   0x08,   0x2300, 0x68,   0x48,   0x68,           0x48},
{       0x6A,   0x4A,   0x0A,   0x2400, 0x6A,   0x4A,   0x6A,           0x4A},
{       0x6B,   0x4B,   0x0B,   0x3500, 0x6B,   0x4B,   0x6B,           0x4B},
{       0x6C,   0x4C,   0x0C,   0x2600, 0x6C,   0x4C,   0x6C,           0x4C},
{       0x3B,   0x3A,   0,      0,      0x3B,   0x3B,   0x3A,           0x3A},
{       0x27,   0x22,   0,      0,      0x27,   0x27,   0x22,           0x22},
{       0x60,   0x7E,   0,      0,      0x60,   0x60,   0x7E,           0x7E},
/* Left Shift*/
{       0x2A,   0,      0,      0,      0,      0,      0,              0},
/* \ZXCVBNM,./ */
{       0x5C,   0x7C,   0x1C,   0,      0x5C,   0x5C,   0x7C,           0x7C},
{       0x7A,   0x5A,   0x1A,   0x2C00, 0x7A,   0x5A,   0x7A,           0x5A},
{       0x78,   0x58,   0x18,   0x2D00, 0x78,   0x58,   0x78,           0x58},
{       0x63,   0x43,   0x03,   0x2E00, 0x63,   0x43,   0x63,           0x43},
{       0x76,   0x56,   0x16,   0x2F00, 0x76,   0x56,   0x76,           0x56},
{       0x62,   0x42,   0x02,   0x3000, 0x62,   0x42,   0x62,           0x42},
{       0x6E,   0x4E,   0x0E,   0x3100, 0x6E,   0x4E,   0x6E,           0x4E},
{       0x6D,   0x4D,   0x0D,   0x3200, 0x6D,   0x4D,   0x6D,           0x4D},
{       0x2C,   0x3C,   0,      0,      0x2C,   0x2C,   0x3C,           0x3C},
{       0x2E,   0x3E,   0,      0,      0x2E,   0x2E,   0x3E,           0x3E},
{       0x2F,   0x3F,   0,      0,      0x2F,   0x2F,   0x3F,           0x3F},
/* Right Shift */
{       0,      0,      0,      0,      0,      0,      0,              0},
/* Print Screen */
{       0,      0,      0,      0,      0,      0,      0,              0},
/* Alt  */
{       0,      0,      0,      0,      0,      0,      0,              0},
/* Space */
{       0x20,   0x20,   0x20,   0,      0x20,   0x20,   0x20,           0x20},
/* Caps */
{       0,      0,      0,      0,      0,      0,      0,              0},
/* F1-F10 */
{       0x3B00, 0x5400, 0x5E00, 0x6800, 0x3B00, 0x3B00, 0x5400,         0x5400},
{       0x3C00, 0x5500, 0x5F00, 0x6900, 0x3C00, 0x3C00, 0x5500,         0x5500},
{       0x3D00, 0x5600, 0x6000, 0x6A00, 0x3D00, 0x3D00, 0x5600,         0x5600},
{       0x3E00, 0x5700, 0x6100, 0x6B00, 0x3E00, 0x3E00, 0x5700,         0x5700},
{       0x3F00, 0x5800, 0x6200, 0x6C00, 0x3F00, 0x3F00, 0x5800,         0x5800},
{       0x4000, 0x5900, 0x6300, 0x6D00, 0x4000, 0x4000, 0x5900,         0x5900},
{       0x4100, 0x5A00, 0x6400, 0x6E00, 0x4100, 0x4100, 0x5A00,         0x5A00},
{       0x4200, 0x5B00, 0x6500, 0x6F00, 0x4200, 0x4200, 0x5B00,         0x5B00},
{       0x4300, 0x5C00, 0x6600, 0x7000, 0x4300, 0x4300, 0x5C00,         0x5C00},
{       0x4400, 0x5D00, 0x6700, 0x7100, 0x4400, 0x4400, 0x5D00,         0x5D00},
/* Num Lock, Scrl Lock */
{       0,      0,      0,      0,      0,      0,      0,              0},
{       0,      0,      0,      0,      0,      0,      0,              0},
/* HOME, Up, Pgup, -kpad, left, center, right, +keypad, end, down, pgdn, ins, del */
{       0x4700, 0x37,   0x7700, 0,      0x37,   0x4700, 0x37,           0x4700},
{       0x4800, 0x38,   0,      0,      0x38,   0x4800, 0x38,           0x4800},
{       0x4900, 0x39,   0x8400, 0,      0x39,   0x4900, 0x39,           0x4900},
{       0x2D,   0x2D,   0,      0,      0x2D,   0x2D,   0x2D,           0x2D},
{       0x4B00, 0x34,   0x7300, 0,      0x34,   0x4B00, 0x34,           0x4B00},
{       0x4C00, 0x35,   0,      0,      0x35,   0x4C00, 0x35,           0x4C00},
{       0x4D00, 0x36,   0x7400, 0,      0x36,   0x4D00, 0x36,           0x4D00},
{       0x2B,   0x2B,   0,      0,      0x2B,   0x2B,   0x2B,           0x2B},
{       0x4F00, 0x31,   0x7500, 0,      0x31,   0x4F00, 0x31,           0x4F00},
{       0x5000, 0x32,   0,      0,      0x32,   0x5000, 0x32,           0x5000},
{       0x5100, 0x33,   0x7600, 0,      0x33,   0x5100, 0x33,           0x5100},
{       0x5200, 0x30,   0,      0,      0x30,   0x5200, 0x30,           0x5200},
{       0x5300, 0x2E,   0,      0,      0x2E,   0x5300, 0x2E,           0x5300}
};
void Init8259()
{
  outb(M_PIC,ICW1);
  outb(S_PIC,ICW1);
  outb(M_PIC+1,M_VEC);
  outb(S_PIC+1,S_VEC);
  outb(M_PIC+1,1<<2);
  outb(S_PIC+1,2);
  outb(M_PIC+1,ICW4);
  outb(S_PIC+1,ICW4);
  outb(M_IMR,0xff);
  outb(S_IMR,0xff);
}
void enable_irq(unsigned short irq_no)
{
irq_mask &= ~(1 << irq_no);
if(irq_no >= 8)
     irq_mask &= ~(1 << 2);
outb(M_PIC + 1, irq_mask & 0xff);
outb(S_PIC + 1, (irq_mask >> 8) & 0xff); 
}
void disable_irq(unsigned short irq_no)
{
        irq_mask |= (1 << irq_no);
        if((irq_mask & 0xFF00)==0xFF00)
                irq_mask |= (1 << 2);
        
        outb(M_PIC+1, irq_mask & 0xFF);
        outb(S_PIC+1, (irq_mask >> 8) & 0xFF);
}
void set_vector(void *handler, unsigned char interrupt, unsigned short control_major)
{
   unsigned short codesegment = 0x08;
   asm volatile("movw %%cs,%0":"=g" (codesegment));

   IDT[interrupt].gate.offset_low    = (unsigned short) (((unsigned long)handler)&0xffff);
   IDT[interrupt].gate.selector      = codesegment;
   IDT[interrupt].gate.access        = control_major;
   IDT[interrupt].gate.offset_high   = (unsigned short) (((unsigned long)handler) >> 16);
}
struct
{ 
  unsigned short limit __attribute__ ((packed));
  union DT_entry *idt  __attribute__ ((packed)); 
} loadidt= { (256 * sizeof(union DT_entry) - 1), IDT };

struct
{
        unsigned short limit __attribute__ ((packed));
        union DT_entry *idt __attribute__ ((packed));
} loadgdt = { (3 * sizeof(union DT_entry) - 1), GDT };

void InitIDT()
{
        int count=0;

        for(count = 16; count < 256; count++)
                set_vector(int_null, count, D_PRESENT + D_INT + D_DPL3);

        set_vector(_int0, 0, D_PRESENT +  D_INT + D_DPL3);
        set_vector(_int1, 1, D_PRESENT +  D_INT + D_DPL3);
        set_vector(_int2, 2, D_PRESENT +  D_INT + D_DPL3);
        set_vector(_int3, 3, D_PRESENT +  D_INT + D_DPL3);
        set_vector(_int4, 4, D_PRESENT +  D_INT + D_DPL3);
        set_vector(_int5, 5, D_PRESENT +  D_INT + D_DPL3);
        set_vector(_int6, 6, D_PRESENT +  D_INT + D_DPL3);
        set_vector(_int7, 7, D_PRESENT +  D_INT + D_DPL3);
        set_vector(_int8, 8, D_PRESENT +  D_INT + D_DPL3);
        set_vector(_int9, 9, D_PRESENT +  D_INT + D_DPL3);
        set_vector(_int10, 10, D_PRESENT +  D_INT + D_DPL3);
        set_vector(_int12, 12, D_PRESENT +  D_INT + D_DPL3);
        set_vector(_int13, 13, D_PRESENT +  D_INT + D_DPL3);
        set_vector(_int14, 14, D_PRESENT +  D_INT + D_DPL3);
        set_vector(_int15, 15, D_PRESENT +  D_INT + D_DPL3);
        set_vector(_int16, 16, D_PRESENT +  D_INT + D_DPL3);

        __asm__(
                "lidt (%0)                 \n"   /* Load the IDT                */
                "pushfl                    \n"   /* Clear the NT flag           */
                "andl $0xffffbfff,(%%esp)  \n"
                "popfl                     \n"
                :
                : "r" ((char *) &loadidt)
        );
        __asm__("sti");
}
inline void initGdt()
{
__asm__ volatile("lgdtl (loadgdt)");
}
void InitKeyboard()
{
        set_vector(_int9kb, M_VEC+1, D_PRESENT + D_INT + D_DPL3); /* IRQ1 Handler */
enable_irq(1);
}

__asm__(
   ".globl int_null        \n"
   "int_null:              \n"
   "   iret                \n" 
);
void _int0(){while(1);}
void _int1(){while(1);}
void _int2(){while(1);}
void _int3(){while(1);}
void _int4(){while(1);}
void _int5(){while(1);}
void _int6(){while(1);}
void _int7(){while(1);}
void _int8(){while(1);}
void _int9(){while(1);}
void _int10(){while(1);}
void _int11(){while(1);}
void _int12(){while(1);}
void _int13(){while(1);}
void _int14(){while(1);}
void _int15(){while(1);}
void _int16(){while(1);}
__asm__(".globl _int9kb \n"
"_int9kb:               \n"
"     pushw %ds         \n"
"     pushw %es         \n"
"     pushw %ss         \n"
"     pushw %ss         \n"
"     popw %ds          \n"
"     popw %es          \n"
"     call keyb_handler \n"
"     popw %ds          \n"
"     popw %es          \n"
"     popa              \n"
"     iret                "
);
void keyb_handler()
{
 char key = inb(0x64);
 if(key & 0x80)
 {
  if(( key == (0x1D + 0x80)) || key ==( 0x2a+ 0x80) || key ==( 0x36 + 0x80) || key == (0x38 + 0x80) ) kstat_curr = KSTAT_NORMAL;
 }
 else
 {
  if(key == 0x3A)
  {
   kstat_curr = (kstat_curr != KSTAT_CAPS) ? KSTAT_CAPS: 0;
  }
  else if (key == 0x45)
  {
   kstat_curr = (kstat_curr != KSTAT_NUM) ? KSTAT_NUM : 0;
  }
  else if (key == 0x2a || key == 0x36)
  {
  if(kstat_curr == 4)
   kstat_curr = 7;
  else if(kstat_curr == 5)
   kstat_curr = 6;
   else kstat_curr = (kstat_curr != KSTAT_SHIFT) ? KSTAT_SHIFT : 0;
  }
  else if (key == 0x1D)
  {
   kstat_curr = (kstat_curr != KSTAT_CTRL) ? KSTAT_CTRL : 0;
  }
  else if (key == 0x38)
  {
   kstat_curr = (kstat_curr != KSTAT_ALT) ? KSTAT_ALT : 0;
  }
  else
  {
   kinput_buffer[kbs] = scan2ascii_table[key][kstat_curr];
   kbs++;
  }
 }
}
void pushbuf()
{
 int i = 0;
 while(kinput_buffer[i] != 0) {kread_buffer[i] = kinput_buffer[i];
 i++;
 }
 int j;
 for( j = 0; j < kbs; j++) kread_buffer[j] = 0;
 kbs = 0;
}
unsigned char getch()
{
	return kinput_buffer[0];
}
