#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int32_t ff_vc1_dqscale[63];
extern int16_t *ac_val2;
extern int q1;
extern int q2;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every second element)
    for (k = 2; k < 8; k += 2)
        ac_val2[k] = (int)(ac_val2[k] * q2 * (unsigned int)ff_vc1_dqscale[q1 - 1] + 131072) >> 18;
}
