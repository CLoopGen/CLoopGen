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
    int16_t local_coeffs[256]; // Use local array to eliminate immediate write to global 'coeffs'
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            int idx = i + j * 16;
            local_coeffs[idx] = coeff; // Store into local array first — removes loop-carried dependence on shared output
        }
    }
    // Now copy local results back to global memory
    for (i = 0; i < 256; i++) {
        coeffs[i] = local_coeffs[i];
    }
}
