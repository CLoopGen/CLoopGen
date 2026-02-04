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
int local_blcounts[32] = {0};
int local_zlcount = 0;
for (int i = 0; i < 256; i++) {
    int bitlen = bitlens[i];
    local_zlcount += (bitlen < 1);
    int blcount = local_blcounts[bitlen];
    syms[(bitlen << 8) + blcount] = i;
    local_blcounts[bitlen]++;
}
for (int j = 0; j < 32; j++) {
    blcounts[j] += local_blcounts[j];
}
zlcount += local_zlcount;
}
