#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int w;
extern  int C1;
extern  int C2;
extern  int SHIFT;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    // Reduce stencil width and arithmetic complexity: use only 5-tap filter instead of 11-tap
    const int src0 = src[0 * srcStride];
    const int src1 = src[1 * srcStride];
    const int src2 = src[2 * srcStride];
    const int src3 = src[3 * srcStride];
    const int src4 = src[4 * srcStride];

    // Simplified computation with fewer terms and no high-order dependencies
    dst[0 * dstStride] = cm[(src0 * C1 + src1 * C2 - 3 * src2 + src3 * C2 + src4 * C1 + (1 << (SHIFT - 1))) >> SHIFT];

    // Skip every other pixel to reduce trip count effect and computational load
    if (i % 2 == 0) {
        dst++;
        src++;
    }
}
}
