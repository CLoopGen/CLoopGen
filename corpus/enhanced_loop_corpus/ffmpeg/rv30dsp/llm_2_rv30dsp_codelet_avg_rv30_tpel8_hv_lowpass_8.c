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
    uint8_t *src_base = src + j * srcStride;
    uint8_t *dst_base = dst + j * dstStride;
    for (i = 0; i < w; i++) {
        int offset = i;
        dst_base[offset] = (((dst_base[offset]) + cm[(src_base[srcStride * -1 + offset - 1] - 12 * src_base[srcStride * -1 + offset] - 6 * src_base[srcStride * -1 + offset + 1] + src_base[srcStride * -1 + offset + 2] + -12 * src_base[srcStride * 0 + offset - 1] + 144 * src_base[srcStride * 0 + offset] + 72 * src_base[srcStride * 0 + offset + 1] - 12 * src_base[srcStride * 0 + offset + 2] + -6 * src_base[srcStride * 1 + offset - 1] + 72 * src_base[srcStride * 1 + offset] + 36 * src_base[srcStride * 1 + offset + 1] - 6 * src_base[srcStride * 1 + offset + 2] + src_base[srcStride * 2 + offset - 1] - 12 * src_base[srcStride * 2 + offset] - 6 * src_base[srcStride * 2 + offset + 1] + src_base[srcStride * 2 + offset + 2] + 128) >> 8] + 1) >> 1);
    }
}
}
