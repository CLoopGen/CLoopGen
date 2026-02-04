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
    // Variant 2: Strided memory access with stride of 8, traversing column-wise in a single loop
    for (i = 0; i < 8; i++) {
        int16_t* base = &coeffs[i];
        for (j = 0; j < 8; j++) {
            *(base + j * 8) = coeff;
        }
    }
}
