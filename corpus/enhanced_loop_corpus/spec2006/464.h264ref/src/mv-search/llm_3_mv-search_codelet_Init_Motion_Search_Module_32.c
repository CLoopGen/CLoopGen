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
    // Variant 2: Reverse Consecutive Memory Access Pattern
    for (bits = 3; bits <= max_ref_bits; bits += 2) {
        imax = (1 << ((bits >> 1) + 1)) - 1;
        imin = imax >> 1;
        // Traverse the array in reverse order, consecutive access
        for (i = imax - 1; i >= imin; i--) {
            refbits[i] = bits;
        }
    }
}
