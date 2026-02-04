#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational load: smaller filter window and lower trip count
for (i = 0; i < w; i++) {
    // Load only necessary taps with reduced stencil width
    const int src0 = src[0 * srcStride];
    const int src1 = src[1 * srcStride];
    const int src2 = src[2 * srcStride];
    const int src3 = src[3 * srcStride];

    // Simplified filtering kernel: fewer terms, lower arithmetic complexity
    dst[0 * dstStride] = cm[((32 * src0 + 64 * src1 + 32 * src2) + 64) >> 7];
    dst[1 * dstStride] = cm[((32 * src1 + 64 * src2 + 32 * src3) + 64) >> 7];

    // Only write two outputs per iteration and reduce pointer updates
    dst++;
    src++;
}
}
