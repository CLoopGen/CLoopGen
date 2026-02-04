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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access, preload data into local arrays to enable consecutive access
    int src_buf[13]; // Local buffer to hold the sliding window of source values
    for (i = 0; i < w; i++) {
        // Load a window of source data into a local array with consecutive indexing
        src_buf[0] = src[-2 * srcStride];
        src_buf[1] = src[-1 * srcStride];
        src_buf[2] = src[0 * srcStride];
        src_buf[3] = src[1 * srcStride];
        src_buf[4] = src[2 * srcStride];
        src_buf[5] = src[3 * srcStride];
        src_buf[6] = src[4 * srcStride];
        src_buf[7] = src[5 * srcStride];
        src_buf[8] = src[6 * srcStride];
        src_buf[9] = src[7 * srcStride];
        src_buf[10] = src[8 * srcStride];
        src_buf[11] = src[9 * srcStride];
        src_buf[12] = src[10 * srcStride];

        // Use consecutive indexing in the computation
        dst[0 * dstStride] = cm[((0 * src_buf[0] + -1 * src_buf[1] + 5 * src_buf[2] + 5 * src_buf[3] + -1 * src_buf[4] + 0 * src_buf[5]) + 4) >> 3];
        dst[1 * dstStride] = cm[((0 * src_buf[1] + -1 * src_buf[2] + 5 * src_buf[3] + 5 * src_buf[4] + -1 * src_buf[5] + 0 * src_buf[6]) + 4) >> 3];
        dst[2 * dstStride] = cm[((0 * src_buf[2] + -1 * src_buf[3] + 5 * src_buf[4] + 5 * src_buf[5] + -1 * src_buf[6] + 0 * src_buf[7]) + 4) >> 3];
        dst[3 * dstStride] = cm[((0 * src_buf[3] + -1 * src_buf[4] + 5 * src_buf[5] + 5 * src_buf[6] + -1 * src_buf[7] + 0 * src_buf[8]) + 4) >> 3];
        dst[4 * dstStride] = cm[((0 * src_buf[4] + -1 * src_buf[5] + 5 * src_buf[6] + 5 * src_buf[7] + -1 * src_buf[8] + 0 * src_buf[9]) + 4) >> 3];
        dst[5 * dstStride] = cm[((0 * src_buf[5] + -1 * src_buf[6] + 5 * src_buf[7] + 5 * src_buf[8] + -1 * src_buf[9] + 0 * src_buf[10]) + 4) >> 3];
        dst[6 * dstStride] = cm[((0 * src_buf[6] + -1 * src_buf[7] + 5 * src_buf[8] + 5 * src_buf[9] + -1 * src_buf[10] + 0 * src_buf[11]) + 4) >> 3];
        dst[7 * dstStride] = cm[((0 * src_buf[7] + -1 * src_buf[8] + 5 * src_buf[9] + 5 * src_buf[10] + -1 * src_buf[11] + 0 * src_buf[12]) + 4) >> 3];

        dst++;
        src++;
    }
}
