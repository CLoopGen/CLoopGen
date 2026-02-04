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
    // Variant 2: Strided memory access - write every 4th element first, then step by 1
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            coeffs[i * 4 + j] = coeff;  // Still covers same indices but emphasizes row-major stride of 4
        }
    }
}
