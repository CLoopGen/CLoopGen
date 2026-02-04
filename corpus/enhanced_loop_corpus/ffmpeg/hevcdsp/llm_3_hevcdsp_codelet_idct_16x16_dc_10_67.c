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
    // Variant 2: Strided memory access with a fixed stride pattern (stride of 4 elements)
    int stride = 4;
    int index;
    for (j = 0; j < 16; j += stride) {
        for (i = 0; i < 16; i++) {
            for (int sj = 0; sj < stride && (j + sj) < 16; sj++) {
                index = i + (j + sj) * 16;
                coeffs[index] = coeff;
            }
        }
    }
}
