#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *dst;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;
extern int16_t *b3;
extern int16_t *b4;
extern int16_t *b5;
extern int16_t *b6;
extern int16_t *b7;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Dual-Access Pattern with Unrolling (unroll factor 2)
    // Processes two elements per iteration to increase data locality and reduce loop overhead
    int unroll = 2;
    int limit = width - (width % unroll);
    for (i = 0; i < limit; i += unroll) {
        // First element
        dst[i] = ((unsigned int)dst[i] - ((int)(-8 * (b0[i] + (unsigned int)b7[i]) + 21 * (b1[i] + (unsigned int)b6[i]) - 46 * (b2[i] + (unsigned int)b5[i]) + 161 * (b3[i] + (unsigned int)b4[i]) + 128) >> 8));
        // Second element
        dst[i+1] = ((unsigned int)dst[i+1] - ((int)(-8 * (b0[i+1] + (unsigned int)b7[i+1]) + 21 * (b1[i+1] + (unsigned int)b6[i+1]) - 46 * (b2[i+1] + (unsigned int)b5[i+1]) + 161 * (b3[i+1] + (unsigned int)b4[i+1]) + 128) >> 8));
    }
    // Handle remaining elements if width is not divisible by 2
    for (; i < width; i++) {
        dst[i] = ((unsigned int)dst[i] - ((int)(-8 * (b0[i] + (unsigned int)b7[i]) + 21 * (b1[i] + (unsigned int)b6[i]) - 46 * (b2[i] + (unsigned int)b5[i]) + 161 * (b3[i] + (unsigned int)b4[i]) + 128) >> 8));
    }
}
