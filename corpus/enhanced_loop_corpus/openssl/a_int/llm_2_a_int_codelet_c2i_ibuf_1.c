#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *p;
extern size_t plen;
extern int pad;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pad = 0, i = 0; i < plen; i += 2)
        pad |= p[i];
}
