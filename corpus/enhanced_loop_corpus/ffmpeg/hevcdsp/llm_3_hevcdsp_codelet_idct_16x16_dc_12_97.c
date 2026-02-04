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
    // Variant 2: Strided memory access with a fixed stride pattern
    // Access memory with a stride of 16, writing one column at a time
    // This increases spatial stride and reduces cache locality
    for (i = 0; i < 16; i++) {
        int16_t *base = &coeffs[i];
        for (j = 0; j < 16; j++) {
            base[j * 16] = coeff;  // Stride of 16 elements (32 bytes assuming int16_t)
        }
    }
}
