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
    int offset = (j & 1) ? srcStride : 0;
    for (i = 0; i < w; i++) {
        int srcIdx = i + offset;
        dst[i] = (((dst[i]) + cm[(36 * src[srcIdx + srcStride * 0] + 54 * src[srcIdx + 1 + srcStride * 0] + 6 * src[srcIdx + 2 + srcStride * 0] + 54 * src[srcIdx + srcStride * 1] + 81 * src[srcIdx + 1 + srcStride * 1] + 9 * src[srcIdx + 2 + srcStride * 1] + 6 * src[srcIdx + srcStride * 2] + 9 * src[srcIdx + 1 + srcStride * 2] + src[srcIdx + 2 + srcStride * 2] + 128) >> 8] + 1) >> 1);
    }
    src += srcStride;
    dst += dstStride;
}
}
