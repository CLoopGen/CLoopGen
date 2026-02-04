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
for (j = 0; j < h; j += 2) {
    for (i = 0; i < w; i++) {
        // First row
        dst[i] = cm[(36 * src[i + srcStride * 0] + 54 * src[i + 1 + srcStride * 0] + 6 * src[i + 2 + srcStride * 0] + 54 * src[i + srcStride * 1] + 81 * src[i + 1 + srcStride * 1] + 9 * src[i + 2 + srcStride * 1] + 6 * src[i + srcStride * 2] + 9 * src[i + 1 + srcStride * 2] + src[i + 2 + srcStride * 2] + 128) >> 8];
        // Second row if exists
        if (j + 1 < h) {
            uint8_t *src_next = src + srcStride;
            uint8_t *dst_next = dst + dstStride;
            dst_next[i] = cm[(36 * src_next[i + srcStride * 0] + 54 * src_next[i + 1 + srcStride * 0] + 6 * src_next[i + 2 + srcStride * 0] + 54 * src_next[i + srcStride * 1] + 81 * src_next[i + 1 + srcStride * 1] + 9 * src_next[i + 2 + srcStride * 1] + 6 * src_next[i + srcStride * 2] + 9 * src_next[i + 1 + srcStride * 2] + src_next[i + 2 + srcStride * 2] + 128) >> 8];
        }
    }
    src += 2 * srcStride;
    dst += 2 * dstStride;
}
}
