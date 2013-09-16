#include <stddef.h>
#include <stdint.h>
void nc_tprintf(char*);
void nc_tscanf(char*);
void nc_tinit();
#define nprintf(q) nc_tprintf(q)
#define nscanf(q) nc_tscanf(q)
