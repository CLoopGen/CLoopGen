#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const float ff_pow_0_7[10];
extern const float ff_pow_0_55[10];
extern  float *Az;
extern float tmp1[49];
extern float tmp2[11];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride of 2 (unrolled-like pattern)
    // Access elements in a strided manner by skipping every other index, adjusting bounds accordingly
    for (i = 0; i < 10; i += 2) {
        int idx = i;
        tmp1[idx + 1] = Az[idx] * ff_pow_0_55[idx];
        tmp2[idx] = Az[idx] * ff_pow_0_7[idx];
        
        if (i + 1 < 10) {
            idx = i + 1;
            tmp1[idx + 1] = Az[idx] * ff_pow_0_55[idx];
            tmp2[idx] = Az[idx] * ff_pow_0_7[idx];
        }
    }
}
