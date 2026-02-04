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
    int local_ref;
    for (bits = 3; bits <= max_ref_bits; bits += 2) {
        imax = (1 << ((bits >> 1) + 1)) - 1;
        imin = imax >> 1;
        local_ref = bits; // Introduce local variable to break direct WAW dependency
        for (i = imin; i < imax; i += 2) { // Modify stride to change access pattern
            refbits[i] = local_ref;
            if (i + 1 < imax) {
                refbits[i + 1] = local_ref;
            }
        }
        // Add artificial dependence: current loop depends on prior iteration's bits
        if (bits > 3) {
            imin = imin - (2 >> 1); // Create loop-carried dependence (RAW)
        }
    }
}
