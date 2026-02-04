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
    // Variant 2: Strided memory access with increased stride (access every second element)
    // Simulates a non-unit stride pattern, still covering equivalent logical range
    for (k = 1; k < 8; k += 2) {  // Stride of 2 in loop index
        ac_val2[k + 8] = (int)(ac_val2[k + 8] * (unsigned int)q2 * ff_vc1_dqscale[q1 - 1] + 131072) >> 18;
        if (k + 1 < 8) {  // Handle next element within bounds
            ac_val2[k + 9] = (int)(ac_val2[k + 9] * (unsigned int)q2 * ff_vc1_dqscale[q1 - 1] + 131072) >> 18;
        }
    }
}
