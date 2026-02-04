#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *p;
extern size_t plen;
extern int pad;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    pad = 0;
    size_t temp = 1;
    for (i = 1; i < plen; i++) {
        pad |= p[temp];
        temp = i + 1;
    }
}
