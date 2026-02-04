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
for (int i = 0; i < 512; i += 2) {
    int idx = i >> 1;
    int bitlen = bitlens[idx];
    int blcount = blcounts[bitlen];
    zlcount += (bitlen < 1) ? 1 : 0;
    syms[(bitlen << 8) + blcount] = idx;
    blcounts[bitlen] += 1;
}
}
