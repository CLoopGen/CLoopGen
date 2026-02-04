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
for (int i = 0; i < 256; i++) {
    int bitlen = bitlens[i];
    zlcount += (bitlen < 1);
    if (bitlen < 32 && blcounts[bitlen] < 256) {
        int blcount = blcounts[bitlen];
        syms[(bitlen << 8) + blcount] = i;
        blcounts[bitlen]++;
    }
}
}
