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
    // Variant 1: Consecutive memory access via pointer arithmetic precomputation
    // Instead of repeatedly calculating src[srcStride * r + i + c], we preload row pointers
    // to enable more sequential access patterns and reduce index computation overhead.

    uint8_t *src_row_m1, *src_row_0, *src_row_1, *src_row_2;
    for (j = 0; j < h; j++) {
        src_row_m1 = src + srcStride * -1;
        src_row_0  = src;
        src_row_1  = src + srcStride *  1;
        src_row_2  = src + srcStride *  2;

        for (i = 0; i < w; i++) {
            int val = (src_row_m1[i - 1] - 12 * src_row_m1[i] - 6 * src_row_m1[i + 1] + src_row_m1[i + 2]
                     - 12 * src_row_0[i - 1] + 144 * src_row_0[i] + 72 * src_row_0[i + 1] - 12 * src_row_0[i + 2]
                     - 6 * src_row_1[i - 1] + 72 * src_row_1[i] + 36 * src_row_1[i + 1] - 6 * src_row_1[i + 2]
                     + src_row_2[i - 1] - 12 * src_row_2[i] - 6 * src_row_2[i + 1] + src_row_2[i + 2] + 128) >> 8;
            dst[i] = cm[val];
        }
        src += srcStride;
        dst += dstStride;
    }
}
