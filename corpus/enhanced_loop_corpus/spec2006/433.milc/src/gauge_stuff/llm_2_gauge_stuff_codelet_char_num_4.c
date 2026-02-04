#include <stdio.h>

#include <inttypes.h>

extern int *dig;
extern int length;
extern int j;
extern int bdig[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2 (unrolling-like pattern)
    // We process two elements per iteration in reverse order, but skip every other index.
    // To maintain validity, we assume length is even and at most 6.
    int k;
    for (k = 0; k < length; k += 2) {
        int idx1 = length - k - 1;
        int idx2 = length - k - 2;
        if (k < length) {
            bdig[k] = 7 - dig[idx1];
        }
        if (k + 1 < length) {
            bdig[k + 1] = 7 - dig[idx2];
        }
    }
}
