#include <stddef.h>
#include <stdint.h>
void nc_tprintf(char*);
void nc_tscanf(char*);
void nc_tinit();
char inb(unsigned int port);
void outb(unsigned int port, unsigned char val);
#define nprintf(q) nc_tprintf(q)
#define nscanf(q) nc_tscanf(q)
