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
    // Variant 2: Strided memory access with increased stride (every second element)
    int stride = 2;
    int index = 0;
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            index = (i * stride) + (j * 8);
            if (index < 64) { // Bound check since we're striding
                coeffs[index] = coeff;
            }
        }
    }
}
