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
    if (j + 1 >= h) break;
    for (i = 0; i < w; i++) {
        int src_center1 = src[srcStride * 0 + i];
        int src_center2 = src[srcStride * 1 + i];
        int filtered1 = (src[srcStride * -1 + i] - 12 * src_center1 + 72 * src_center1 - 12 * src[srcStride * 1 + i] + 144 * src_center1 + 128) >> 8;
        int filtered2 = (src[srcStride * 0 + i] - 12 * src_center2 + 72 * src_center2 - 12 * src[srcStride * 2 + i] + 144 * src_center2 + 128) >> 8;
        dst[i] = ((dst[i] + cm[filtered1] + 1) >> 1);
        dst[dstStride + i] = ((dst[dstStride + i] + cm[filtered2] + 1) >> 1);
    }
    src += 2 * srcStride;
    dst += 2 * dstStride;
}
}
