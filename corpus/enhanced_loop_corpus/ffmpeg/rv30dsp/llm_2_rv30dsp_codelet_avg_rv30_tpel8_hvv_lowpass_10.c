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
    uint8_t *src_base = src + srcStride * (-1);
    uint8_t *dst_row = dst;
    for (i = 0; i < w; i++) {
        int offset = i;
        dst_row[offset] = (((dst_row[offset]) + cm[(src_base[offset - 1] - 12 * src_base[offset] - 6 * src_base[offset + 1] + src_base[offset + 2] + -6 * (src_base + srcStride)[offset - 1] + 72 * (src_base + srcStride)[offset] + 36 * (src_base + srcStride)[offset + 1] - 6 * (src_base + srcStride)[offset + 2] + -12 * (src_base + 2*srcStride)[offset - 1] + 144 * (src_base + 2*srcStride)[offset] + 72 * (src_base + 2*srcStride)[offset + 1] - 12 * (src_base + 2*srcStride)[offset + 2] + (src_base + 3*srcStride)[offset - 1] - 12 * (src_base + 3*srcStride)[offset] - 6 * (src_base + 3*srcStride)[offset + 1] + (src_base + 3*srcStride)[offset + 2] + 128) >> 8] + 1) >> 1);
    }
    src += srcStride;
    dst += dstStride;
}
}
