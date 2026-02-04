#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dst;
extern int32_t *b0;
extern int32_t *b1;
extern int32_t *b2;
extern int32_t *b3;
extern int32_t *b4;
extern int32_t *b5;
extern int32_t *b6;
extern int32_t *b7;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (stride of 2)
    for (i = 0; i < width; i += 2) {
        if (i + 1 < width) {
            // Process two elements with stride 2 for better cache behavior and memory bandwidth utilization
            dst[i] = ((unsigned int)dst[i] + ((int)(-2 * (b0[i] + (unsigned int)b7[i]) + 10 * (b1[i] + (unsigned int)b6[i]) - 25 * (b2[i] + (unsigned int)b5[i]) + 81 * (b3[i] + (unsigned int)b4[i]) + 128) >> 8));
            dst[i+1] = ((unsigned int)dst[i+1] + ((int)(-2 * (b0[i+1] + (unsigned int)b7[i+1]) + 10 * (b1[i+1] + (unsigned int)b6[i+1]) - 25 * (b2[i+1] + (unsigned int)b5[i+1]) + 81 * (b3[i+1] + (unsigned int)b4[i+1]) + 128) >> 8));
        } else {
            // Handle edge case when width is odd
            dst[i] = ((unsigned int)dst[i] + ((int)(-2 * (b0[i] + (unsigned int)b7[i]) + 10 * (b1[i] + (unsigned int)b6[i]) - 25 * (b2[i] + (unsigned int)b5[i]) + 81 * (b3[i] + (unsigned int)b4[i]) + 128) >> 8));
        }
    }
}
