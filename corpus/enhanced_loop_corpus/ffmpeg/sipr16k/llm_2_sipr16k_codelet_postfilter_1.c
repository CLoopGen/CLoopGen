#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const float ff_pow_0_5[16];
extern float *iir_mem;
extern float *filt_mem[2];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2, unrolled to handle remaining elements
    int stride = 2;
    for (i = 0; i < 16; i += stride) {
        filt_mem[0][i] = iir_mem[i] * ff_pow_0_5[i];
        if (i + 1 < 16) {
            filt_mem[0][i + 1] = iir_mem[i + 1] * ff_pow_0_5[i + 1];
        }
    }
}
