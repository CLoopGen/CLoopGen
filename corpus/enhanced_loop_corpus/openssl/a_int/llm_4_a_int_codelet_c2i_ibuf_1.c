#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *p;
extern size_t plen;
extern int pad;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pad = 0, i = 1; i < plen; i++) {
        if ((i & 1) == 0) continue;
        pad |= p[i];
    }
}
