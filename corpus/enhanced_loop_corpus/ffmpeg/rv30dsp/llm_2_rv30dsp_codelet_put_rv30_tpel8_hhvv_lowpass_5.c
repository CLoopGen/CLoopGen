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
for (j = 0; j < h; j++) {
    uint8_t *src_row0 = src + srcStride * 0;
    uint8_t *src_row1 = src + srcStride * 1;
    uint8_t *src_row2 = src + srcStride * 2;
    for (i = 0; i < w; i++) {
        int val = 36 * src_row0[i] + 54 * src_row0[i+1] + 6 * src_row0[i+2] +
                  54 * src_row1[i] + 81 * src_row1[i+1] + 9 * src_row1[i+2] +
                   6 * src_row2[i] +  9 * src_row2[i+1] + 1 * src_row2[i+2];
        dst[i] = cm[(val + 128) >> 8];
    }
    src += srcStride;
    dst += dstStride;
}
}
