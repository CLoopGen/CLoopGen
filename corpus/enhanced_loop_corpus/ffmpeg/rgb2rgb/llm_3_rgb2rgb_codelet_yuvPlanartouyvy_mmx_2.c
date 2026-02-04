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
    // Variant 2: Strided access using index-based arithmetic instead of pointer arithmetic
    // All accesses are done via base + index*stride pattern, enabling more predictable memory behavior
    int y_idx = 0;
    int u_idx = 0;
    int v_idx = 0;
    int d_idx = 0;

    for (y = 0; y < height; y++) {
        // Update indices using stride values
        y_idx += lumStride;
        d_idx += dstStride;

        // Update chroma indices only when crossing chroma row boundary
        if ((y & (vertLumPerChroma - 1)) == (vertLumPerChroma - 1)) {
            u_idx += chromStride;
            v_idx += chromStride;
        }
    }

    // Update external pointers based on computed offsets from original bases
    ysrc += y_idx;
    usrc += u_idx;
    vsrc += v_idx;
    dst += d_idx;
}
