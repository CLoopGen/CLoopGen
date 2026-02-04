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
for (kk = 0; kk < 624 - 397; kk += 2) {
    unsigned long y1 = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
    mt[kk] = mt[kk + 397] ^ (y1 >> 1) ^ (((y1) & 1) ? 2567483615UL : 0);

    if (kk + 1 < 624 - 397) {
        unsigned long y2 = (mt[kk + 1] & UPPER_MASK) | (mt[kk + 2] & LOWER_MASK);
        mt[kk + 1] = mt[kk + 398] ^ (y2 >> 1) ^ (((y2) & 1) ? 2567483615UL : 0);
    }
}
}
