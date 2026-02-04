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
    // Variant 1: Consecutive memory access with pointer pre-increment and array indexing
    // Instead of conditionally updating usrc/vsrc every few rows, simulate consecutive layout
    // by treating chroma as being updated once per full block of lum lines
    uint8_t *y_ptr = ysrc;
    uint8_t *u_ptr = usrc;
    uint8_t *v_ptr = vsrc;
    uint8_t *d_ptr = dst;

    for (y = 0; y < height; y++) {
        y_ptr += lumStride;
        d_ptr += dstStride;

        // Update chroma pointers only at the end of each chroma row block
        if ((y & (vertLumPerChroma - 1)) == (vertLumPerChroma - 1)) {
            u_ptr += chromStride;
            v_ptr += chromStride;
        }
    }

    // Write back to extern pointers to preserve side effects
    ysrc = y_ptr;
    usrc = u_ptr;
    vsrc = v_ptr;
    dst = d_ptr;
}
