#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int srcStride;
extern int dstStride[];
extern int srcSliceH;
extern int inc_size;
extern int width;
extern uint8_t *dest[3];
extern int x;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled for spatial locality
    uint8_t *src0 = src;
    uint8_t *dst0 = dest[0];
    uint8_t *dst1 = dest[1];
    uint8_t *dst2 = dest[2];

    for (h = 0; h < srcSliceH; h++) {
        uint8_t *row_src = src0 + h * srcStride;
        uint8_t *row_dst0 = dst0 + h * dstStride[0];
        uint8_t *row_dst1 = dst1 + h * dstStride[1];
        uint8_t *row_dst2 = dst2 + h * dstStride[2];

        for (x = 0; x < width; x++) {
            uint8_t *current_src = row_src + x * inc_size;
            row_dst0[x] = current_src[0];
            row_dst1[x] = current_src[1];
            row_dst2[x] = current_src[2];
        }
    }
}
