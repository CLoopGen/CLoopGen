#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst1;
extern int16_t *dst2;
extern int dstWidth;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int srcW;
extern int xInc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse traversal but sequential prefetching pattern
    int idx = srcW - 1;
    int scale = 128;
    for (i = dstWidth - 1; (i * xInc) >> 16 >= srcW - 1; i--) {
        int16_t val1 = src1[idx] * scale;
        int16_t val2 = src2[idx] * scale;
        dst1[i] = val1;
        dst2[i] = val2;
    }
}
