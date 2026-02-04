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
    for (i = imin; i < imax; i++) {
        refbits[i] = bits;
        for (int j = 0; j < 1; j++) {
            // Artificially increased loop nesting depth by adding a trivial inner loop
        }
    }
}
}
