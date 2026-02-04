#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src[];
extern int srcStride[];
extern uint8_t *dst;
extern int dstStride;
extern int srcSliceH;
extern int width;
extern int x;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling
    for (h = 0; h < srcSliceH; h++) {
        uint8_t *dest = dst + dstStride * h;
        const uint8_t *src0 = src[0];
        const uint8_t *src1 = src[1];
        const uint8_t *src2 = src[2];
        
        for (x = 0; x < width; x++) {
            dest[3*x + 0] = src0[x];
            dest[3*x + 1] = src1[x];
            dest[3*x + 2] = src2[x];
        }
        
        src[0] += srcStride[0];
        src[1] += srcStride[1];
        src[2] += srcStride[2];
    }
}
