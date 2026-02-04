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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of using strided access with src[srcStride * row + col], we precompute base pointers per row
    // to enable more consecutive-like access and improve cache locality.
    for (int j = 0; j < h; j++) {
        uint8_t *src_row_m1 = src - srcStride;
        uint8_t *src_row_0 = src;
        uint8_t *src_row_1 = src + srcStride;
        uint8_t *src_row_2 = src + 2 * srcStride;
        for (int i = 0; i < w; i++) {
            int val = (src_row_m1[i - 1] - 12 * src_row_m1[i + 1] - 6 * src_row_m1[i] + src_row_m1[i + 2]
                     - 12 * src_row_0[i - 1] + 144 * src_row_0[i + 1] + 72 * src_row_0[i] - 12 * src_row_0[i + 2]
                     - 6 * src_row_1[i - 1] + 72 * src_row_1[i + 1] + 36 * src_row_1[i] - 6 * src_row_1[i + 2]
                     + src_row_2[i - 1] - 12 * src_row_2[i + 1] - 6 * src_row_2[i] + src_row_2[i + 2] + 128) >> 8;
            dst[i] = ((dst[i] + cm[val] + 1) >> 1);
        }
        src += srcStride;
        dst += dstStride;
    }
}
