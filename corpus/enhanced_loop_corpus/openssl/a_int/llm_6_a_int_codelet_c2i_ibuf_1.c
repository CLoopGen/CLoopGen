#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *p;
extern size_t plen;
extern int pad;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    pad = 0;
    for (i = 1; i < plen; i++) {
        pad = pad | (p[i] & 0xFF);
    }
}
