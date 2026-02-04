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
for (int outer = 0; outer < 10 && kk < 624 - 1; outer++) {
    for (int inner = 0; inner < 62 && kk < 624 - 1; inner++) {
        unsigned long y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
        mt[kk] = mt[kk + (397 - 624)] ^ (y >> 1) ^ (((y) & 1) ? 2567483615UL : 0);
        kk++;
    }
}
}
