#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *b;
extern size_t blen;
extern unsigned int pad;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    pad = 0;
    i = 1;
    for (; i < blen; i++) {
        pad |= b[i];
    }
}
