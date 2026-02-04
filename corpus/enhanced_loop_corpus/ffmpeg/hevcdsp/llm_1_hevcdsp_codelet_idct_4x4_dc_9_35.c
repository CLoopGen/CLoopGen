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
    // Variant 2: Strided memory access with stride of 2, accessing every second element
    int idx;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 2; i++) {
            idx = (i * 2) + (j * 2) * 4;
            coeffs[idx] = coeff;
            coeffs[idx + 1] = coeff;           // Fill two consecutive in row
            coeffs[idx + 4] = coeff;          // Fill two in next row at same columns
            coeffs[idx + 5] = coeff;
        }
    }
}
