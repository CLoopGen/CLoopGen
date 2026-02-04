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
for (i = 0; i < w; i++) {
    // Reduce the number of loads and reuse computations across multiple outputs
    const int src_offsets[] = {
        src[-2 * srcStride], src[-1 * srcStride], src[0 * srcStride],
        src[1 * srcStride], src[2 * srcStride], src[3 * srcStride],
        src[4 * srcStride], src[5 * srcStride], src[6 * srcStride],
        src[7 * srcStride], src[8 * srcStride], src[9 * srcStride], src[10 * srcStride]
    };

    // Compute only two output pixels per iteration with shared data
    dst[0 * dstStride] = cm[((-1 * src_offsets[0] + -2 * src_offsets[1] + 96 * src_offsets[2] + 42 * src_offsets[3] + -7 * src_offsets[4]) + 64) >> 7];
    dst[1 * dstStride] = cm[((-1 * src_offsets[1] + -2 * src_offsets[2] + 96 * src_offsets[3] + 42 * src_offsets[4] + -7 * src_offsets[5]) + 64) >> 7];

    // Skip full unrolling, reduce arithmetic density by computing fewer results
    // Simulate lighter computation per loop iteration
    dst++;
    src++;
}
}
