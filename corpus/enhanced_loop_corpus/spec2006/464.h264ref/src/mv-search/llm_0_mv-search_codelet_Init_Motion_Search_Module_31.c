#include <stdio.h>

#include <inttypes.h>

extern int *mvbits;
extern int bits;
extern int i;
extern int imin;
extern int imax;
extern int max_mv_bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (bits = 3; bits <= max_mv_bits; bits += 2) {
    imax = 1 << (bits >> 1);
    imin = imax >> 1;
    i = imin;
    for (; i < imax; i++) {
        mvbits[-i] = mvbits[i] = bits;
    }
}
}
