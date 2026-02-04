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
for (int i = 0; i < 256; i += 4) {
    for (int j = 0; j < 4 && (i + j) < 256; j++) {
        int idx = i + j;
        int bitlen = bitlens[idx];
        int blcount = blcounts[bitlen];
        zlcount += bitlen < 1;
        syms[(bitlen << 8) + blcount] = idx;
        blcounts[bitlen]++;
    }
}
}
