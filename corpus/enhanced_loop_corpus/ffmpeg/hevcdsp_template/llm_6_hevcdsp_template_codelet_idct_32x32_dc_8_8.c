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
    for (j = 0; j < 32; j++) {
        int16_t temp_coeff = coeff; // Introduce temporary to create local dependency
        for (i = 0; i < 32; i++) {
            int idx = i + j * 32;
            coeffs[idx] = temp_coeff; // RAW dependency: temp_coeff must be read after write
            temp_coeff += 1; // WAW: multiple writes to temp_coeff, creating intra-loop dependency
        }
        coeff = temp_coeff; // Update global state with final value (loop-carried dependency across j)
    }
}
