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
            // Process two elements with stride 2 for better spatial access pattern exploration
            dst[i] = ((unsigned int)dst[i] - ((int)(-8 * (b0[i] + (unsigned int)b7[i]) + 21 * (b1[i] + (unsigned int)b6[i]) - 46 * (b2[i] + (unsigned int)b5[i]) + 161 * (b3[i] + (unsigned int)b4[i]) + 128) >> 8));
            dst[i+1] = ((unsigned int)dst[i+1] - ((int)(-8 * (b0[i+1] + (unsigned int)b7[i+1]) + 21 * (b1[i+1] + (unsigned int)b6[i+1]) - 46 * (b2[i+1] + (unsigned int)b5[i+1]) + 161 * (b3[i+1] + (unsigned int)b4[i+1]) + 128) >> 8));
        } else {
            dst[i] = ((unsigned int)dst[i] - ((int)(-8 * (b0[i] + (unsigned int)b7[i]) + 21 * (b1[i] + (unsigned int)b6[i]) - 46 * (b2[i] + (unsigned int)b5[i]) + 161 * (b3[i] + (unsigned int)b4[i]) + 128) >> 8));
        }
    }
}
