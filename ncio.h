#ifndef _NCIO_H
#define _NCIO_H
#define _KSTAT_CURR
#include <stddef.h>
#include <stdint.h>
#define F
#include "Keyboard.h"
void nc_tprintf(char*);
void nc_tscanf(char*);
void nc_tinit();
inline char inb(unsigned int port);
inline void outb(unsigned int port, unsigned char val);
//#define nprintf(q) nc_tprintf(q)
//#define nscanf(q) nc_tscanf(q)
#endif
