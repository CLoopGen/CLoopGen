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
    // Variant 2: Strided memory access with a fixed stride of 4 (unrolled-like access pattern)
    // Access elements with a stride of 4 within each row, cycling through multiple phases
    for (int phase = 0; phase < 4; phase++) {
        for (j = 0; j < 16; j++) {
            for (i = phase; i < 16; i += 4) {
                coeffs[i + j * 16] = coeff;
            }
        }
    }
}
