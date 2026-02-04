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
    int temp_bits;
    for (bits = 3; bits <= max_mv_bits; bits += 2) {
        temp_bits = bits; // Introduce temporary to break potential WAW on 'bits'
        imax = 1 << (temp_bits >> 1);
        imin = imax >> 1;
        // Introduce loop-carried dependence via ordered write pattern
        for (i = imin; i < imax; i++) {
            mvbits[-i] = temp_bits;
            mvbits[i] = mvbits[-i]; // RAW dependency: read after write to mvbits[-i]
        }
    }
}
