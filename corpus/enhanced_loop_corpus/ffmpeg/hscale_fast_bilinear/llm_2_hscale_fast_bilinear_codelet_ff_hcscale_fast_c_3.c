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
    // Variant 1: Consecutive memory access with reverse traversal and unrolling by 2
    int idx = (dstWidth - 1) * xInc;
    for (i = dstWidth - 1; (idx >> 16) >= srcW - 1; i--, idx -= xInc) {
        int mapped_idx = srcW - 1;
        dst1[i] = src1[mapped_idx] * 128;
        dst2[i] = src2[mapped_idx] * 128;

        if (i == 0) break; // Prevent overflow when unrolling
        i--;
        idx -= xInc;
        if ((idx >> 16) < srcW - 1) break;
        dst1[i] = src1[mapped_idx] * 128;
        dst2[i] = src2[mapped_idx] * 128;
    }
}
