#include <stdio.h>

#include <inttypes.h>

extern int *refbits;
extern int bits;
extern int i;
extern int imin;
extern int imax;
extern int max_ref_bits;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    for (bits = 3; bits <= max_ref_bits; bits += 2) {
        imax = (1 << ((bits >> 1) + 1)) - 1;
        imin = imax >> 1;
        int stride = 2;
        for (i = imin; i < imax; i += stride) {
            refbits[i] = bits;
        }
        // Handle potential odd index if stride skips last element
        if ((imax - 1) % 2 != 0 && (imax - 1) >= imin) {
            refbits[imax - 1] = bits;
        }
    }
}
