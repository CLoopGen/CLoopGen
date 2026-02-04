#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access using index scaling (simulating non-unit stride via arithmetic)
    // Assume dstStride and srcStride are multiples of 8, unroll by row using direct indexing
    ptrdiff_t d_stride = dstStride;
    ptrdiff_t s_stride = srcStride;
    uint8_t *base_dst = dst;
    uint8_t *base_src = src;

    for (i = 0; i < h; i++) {
        ptrdiff_t di = i * d_stride;
        ptrdiff_t si = i * s_stride;

        base_dst[di + 0] = cm[((0 * base_src[si - 2] + -1 * base_src[si - 1] + 5 * base_src[si + 0] + 5 * base_src[si + 1] + -1 * base_src[si + 2] + 0 * base_src[si + 3]) + 4) >> 3];
        base_dst[di + 1] = cm[((0 * base_src[si - 1] + -1 * base_src[si + 0] + 5 * base_src[si + 1] + 5 * base_src[si + 2] + -1 * base_src[si + 3] + 0 * base_src[si + 4]) + 4) >> 3];
        base_dst[di + 2] = cm[((0 * base_src[si + 0] + -1 * base_src[si + 1] + 5 * base_src[si + 2] + 5 * base_src[si + 3] + -1 * base_src[si + 4] + 0 * base_src[si + 5]) + 4) >> 3];
        base_dst[di + 3] = cm[((0 * base_src[si + 1] + -1 * base_src[si + 2] + 5 * base_src[si + 3] + 5 * base_src[si + 4] + -1 * base_src[si + 5] + 0 * base_src[si + 6]) + 4) >> 3];
        base_dst[di + 4] = cm[((0 * base_src[si + 2] + -1 * base_src[si + 3] + 5 * base_src[si + 4] + 5 * base_src[si + 5] + -1 * base_src[si + 6] + 0 * base_src[si + 7]) + 4) >> 3];
        base_dst[di + 5] = cm[((0 * base_src[si + 3] + -1 * base_src[si + 4] + 5 * base_src[si + 5] + 5 * base_src[si + 6] + -1 * base_src[si + 7] + 0 * base_src[si + 8]) + 4) >> 3];
        base_dst[di + 6] = cm[((0 * base_src[si + 4] + -1 * base_src[si + 5] + 5 * base_src[si + 6] + 5 * base_src[si + 7] + -1 * base_src[si + 8] + 0 * base_src[si + 9]) + 4) >> 3];
        base_dst[di + 7] = cm[((0 * base_src[si + 5] + -1 * base_src[si + 6] + 5 * base_src[si + 7] + 5 * base_src[si + 8] + -1 * base_src[si + 9] + 0 * base_src[si + 10]) + 4) >> 3];
    }
}
