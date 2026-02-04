#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned long UPPER_MASK;
extern  unsigned long LOWER_MASK;
extern unsigned long * mt;
extern int kk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (kk = 0; kk < 624 - 397; kk++) {
    unsigned long y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
    unsigned long z = y >> 1;
    unsigned long t = ((y) & 1) ? 2567483615UL : 0;
    mt[kk] = mt[kk + 397] ^ z ^ t;
}
}
