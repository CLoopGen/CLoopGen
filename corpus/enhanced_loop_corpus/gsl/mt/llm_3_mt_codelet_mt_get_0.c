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
const int stride = 4;
for (kk = 0; kk < 624 - 397; kk++) {
    int index = (kk * stride) % (624 - 397);
    unsigned long y = (mt[index] & UPPER_MASK) | (mt[index + 1] & LOWER_MASK);
    mt[index] = mt[index + 397] ^ (y >> 1) ^ (((y) & 1) ? 2567483615UL : 0);
}
}
