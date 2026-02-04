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
int indices[256];
for (int i = 0; i < 256; i++) {
    indices[i] = i;
}
for (int step = 0; step < 256; step++) {
    int i = indices[step]; 
    int bitlen = bitlens[i];
    int blcount = blcounts[bitlen];
    zlcount += bitlen < 1;
    syms[(bitlen << 8) + blcount] = i;
    blcounts[bitlen]++;
}
}
