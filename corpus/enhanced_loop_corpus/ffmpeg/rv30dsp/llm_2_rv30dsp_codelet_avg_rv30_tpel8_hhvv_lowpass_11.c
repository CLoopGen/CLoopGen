#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int w;
extern  int h;
extern  uint8_t *cm;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Prefetching and Linear Indexing
    // Instead of 2D indexing with stride, we precompute base pointers and access src/dst as linear arrays
    // This improves cache locality by accessing memory sequentially

    uint8_t *src_base = src;
    uint8_t *dst_base = dst;
    for (j = 0; j < h; j++) {
        uint8_t *src_row = src_base + j * srcStride;
        uint8_t *dst_row = dst_base + j * dstStride;
        for (i = 0; i < w; i++) {
            int idx = i;
            int s0 = src_row[idx] + srcStride * 0;
            int s1 = src_row[idx + 1] + srcStride * 0;
            int s2 = src_row[idx + 2] + srcStride * 0;
            int s3 = src_row[idx] + srcStride * 1;
            int s4 = src_row[idx + 1] + srcStride * 1;
            int s5 = src_row[idx + 2] + srcStride * 1;
            int s6 = src_row[idx] + srcStride * 2;
            int s7 = src_row[idx + 1] + srcStride * 2;
            int s8 = src_row[idx + 2] + srcStride * 2;

            dst_row[i] = (((dst_row[i]) + cm[(36 * src_row[s0] + 54 * src_row[s1] + 6 * src_row[s2] + 
                                          54 * src_row[s3] + 81 * src_row[s4] + 9 * src_row[s5] + 
                                          6 * src_row[s6] + 9 * src_row[s7] + src_row[s8] + 128) >> 8] + 1) >> 1);
        }
    }
}
