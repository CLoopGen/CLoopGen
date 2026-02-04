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
    // Variant 2: Consecutive reversed access – process arrays from high to low index
    // Changes access pattern to reverse sequential order
    for (i = 9; i >= 0; i--) {
        tmp1[i + 1] = Az[i] * ff_pow_0_55[i];
        tmp2[i] = Az[i] * ff_pow_0_7[i];
    }
}
