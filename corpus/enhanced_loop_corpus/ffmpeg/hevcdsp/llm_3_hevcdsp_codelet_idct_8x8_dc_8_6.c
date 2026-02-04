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
    // Variant 2: Strided memory access with a fixed stride of 8, writing one column at a time
    int idx = 0;
    for (j = 0; j < 8; j++) {
        idx = j;
        for (i = 0; i < 8; i++) {
            coeffs[idx] = coeff;
            idx += 8;  // Stride of 8 for column-wise traversal
        }
    }
}
