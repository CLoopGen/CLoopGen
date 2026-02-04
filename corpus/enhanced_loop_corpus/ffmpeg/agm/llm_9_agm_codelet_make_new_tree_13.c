#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *bitlens;
extern int zlcount;
extern int blcounts[32];
extern int syms[8192];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 16; outer++) {
    for (int inner = 0; inner < 16; inner++) {
        int i = (outer << 4) | inner;
        int bitlen = bitlens[i];
        int blcount = blcounts[bitlen];
        zlcount += (bitlen == 0);
        syms[(bitlen * 256) + blcount] = i;
        blcounts[bitlen] = blcount + 1;
    }
}
}
