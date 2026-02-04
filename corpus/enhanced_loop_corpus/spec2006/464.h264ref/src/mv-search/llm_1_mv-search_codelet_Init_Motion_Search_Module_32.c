#include <stdio.h>

#include <inttypes.h>

extern int *refbits;
extern int bits;
extern int i;
extern int imin;
extern int imax;
extern int max_ref_bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (bits = 3; bits <= max_ref_bits; bits += 2) {
    imax = (1 << ((bits >> 1) + 1)) - 1;
    imin = imax >> 1;
    // Decreased effective loop nesting by inlining the inner loop logic with stride simulation
    for (i = imin; i < imax; i += 4) {
        if (i < imax) refbits[i] = bits;
        if (i + 1 < imax) refbits[i + 1] = bits;
        if (i + 2 < imax) refbits[i + 2] = bits;
        if (i + 3 < imax) refbits[i + 3] = bits;
    }
}
}
