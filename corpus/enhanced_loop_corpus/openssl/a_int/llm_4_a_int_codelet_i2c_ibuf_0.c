#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *b;
extern size_t blen;
extern unsigned int pad;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pad = 0, i = 1; i < blen; i++) {
        if (b[i] == 0) continue;
        pad |= b[i];
    }
}
