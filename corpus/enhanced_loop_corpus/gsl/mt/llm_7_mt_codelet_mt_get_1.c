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
    unsigned long temp[624];
    int start_kk = kk;
    for (; kk < 624 - 1; kk++) {
        unsigned long y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
        temp[kk - start_kk] = mt[kk + (397 - 624)] ^ (y >> 1) ^ (((y) & 1) ? 2567483615UL : 0);
    }
    for (int i = 0; i < (624 - 1) - start_kk; i++) {
        mt[start_kk + i] = temp[i];
    }
}
