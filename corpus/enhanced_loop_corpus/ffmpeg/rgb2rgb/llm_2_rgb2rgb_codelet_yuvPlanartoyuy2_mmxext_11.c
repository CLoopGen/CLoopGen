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
    // This variant assumes height is even and processes two rows at a time to promote consecutive access patterns
    // and improve cache locality by reducing conditional updates of chroma pointers.

    for (y = 0; y < height; y += 2) {
        ysrc += lumStride;
        dst += dstStride;

        // First row: check if this row triggers chroma step
        if ((y & (vertLumPerChroma - 1)) == vertLumPerChroma - 1) {
            usrc += chromStride;
            vsrc += chromStride;
        }

        // Second row: advance luminance and destination
        ysrc += lumStride;
        dst += dstStride;

        // Check if the next row (y+1) triggers chroma step
        int next_y = y + 1;
        if ((next_y < height) && ((next_y & (vertLumPerChroma - 1)) == vertLumPerChroma - 1)) {
            usrc += chromStride;
            vsrc += chromStride;
        }
    }
}
