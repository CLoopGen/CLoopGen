#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *b;
extern size_t blen;
extern unsigned int pad;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pad = 0, i = 1; i < blen; i += 2) {
        pad |= b[i];
        if (i + 1 < blen)
            pad |= b[i + 1];
    }
}
