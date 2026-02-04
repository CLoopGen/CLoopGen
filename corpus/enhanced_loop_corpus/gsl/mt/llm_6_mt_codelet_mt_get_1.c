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
    for (; kk < 624 - 1; kk++) {
        unsigned long y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
        unsigned long z = mt[kk + (397 - 624)] ^ (y >> 1);
        if ((y & 1)) {
            z ^= 2567483615UL;
        }
        mt[kk] = z;
    }
}
