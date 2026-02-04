#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *z;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Original strided access is transformed to consecutive by reordering computations
    // We process elements in increasing order of destination index to improve spatial locality
    for (k = 1; k < 32; k++) {
        int idx1 = 64 + 2 * k;
        int idx2 = idx1 + 1;
        z[idx1] = -z[64 - k];
        z[idx2] = z[k + 1];
    }
}
