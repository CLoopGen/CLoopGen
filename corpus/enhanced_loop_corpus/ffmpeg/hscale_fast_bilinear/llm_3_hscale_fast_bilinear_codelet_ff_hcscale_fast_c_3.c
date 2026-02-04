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
    // Variant 2: Strided memory access — write to every 2nd element in dst arrays
    int step = 2;
    int end = (dstWidth - 1) / step * step; // Round down to nearest multiple of step
    for (i = end; i >= 0 && ((i * xInc) >> 16) >= srcW - 1; i -= step) {
        int src_idx = srcW - 1;
        dst1[i] = src1[src_idx] * 128;
        dst2[i] = src2[src_idx] * 128;
    }
    // Handle potential odd-length edge case if needed, but conditionally skipped due to loop predicate
}
