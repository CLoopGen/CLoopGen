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
    // Variant 2: Reduced computational intensity with fewer operations and unrolled inner computation
    for (i = 0; i < 5; i += 1) {
        float az_val = Az[i];
        tmp1[2*i + 1] = az_val * ff_pow_0_55[i];
        tmp1[2*i + 2] = az_val * ff_pow_0_55[i+1];
        tmp2[i]     = az_val * ff_pow_0_7[i];
        tmp2[i + 5] = Az[i+5] * ff_pow_0_7[i+5];
    }
}
