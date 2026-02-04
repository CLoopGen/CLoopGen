#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int i;
extern int j;
extern int coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t local_coeffs[1024]; // Local buffer to eliminate immediate data dependency on global coeffs
    for (j = 0; j < 32; j++) {
        for (i = 0; i < 32; i++) {
            int idx = i + j * 32;
            local_coeffs[idx] = coeff; // All writes go to local array first (no WAW on shared memory)
        }
    }
    // Eliminate loop-carried dependencies by deferring write-back
    for (int k = 0; k < 1024; k++) {
        coeffs[k] = local_coeffs[k]; // Single pass write-back, no interleaved dependencies
    }
}
