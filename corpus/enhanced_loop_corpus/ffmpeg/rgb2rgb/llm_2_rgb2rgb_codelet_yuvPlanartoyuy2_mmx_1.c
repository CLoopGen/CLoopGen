#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ysrc;
extern  uint8_t *usrc;
extern  uint8_t *vsrc;
extern uint8_t *dst;
extern int height;
extern int lumStride;
extern int chromStride;
extern int dstStride;
extern int vertLumPerChroma;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 iterations
    // This variant assumes height is even; processes two rows at a time to promote consecutive access patterns
    for (y = 0; y < height - 1; y += 2) {
        // Process current and next row in lum and dst
        ysrc += lumStride;
        dst += dstStride;

        // Check chroma step for current row
        if ((y & (vertLumPerChroma - 1)) == vertLumPerChroma - 1) {
            usrc += chromStride;
            vsrc += chromStride;
        }

        // Move to next row
        ysrc += lumStride;
        dst += dstStride;

        // Check chroma step for next row
        int next_y = y + 1;
        if ((next_y & (vertLumPerChroma - 1)) == vertLumPerChroma - 1) {
            usrc += chromStride;
            vsrc += chromStride;
        }
    }

    // Handle remaining row if height is odd
    if (y < height) {
        ysrc += lumStride;
        dst += dstStride;
        if ((y & (vertLumPerChroma - 1)) == vertLumPerChroma - 1) {
            usrc += chromStride;
            vsrc += chromStride;
        }
    }
}
