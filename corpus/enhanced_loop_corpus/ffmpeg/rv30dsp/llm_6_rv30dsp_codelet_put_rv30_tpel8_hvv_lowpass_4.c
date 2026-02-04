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
    uint8_t temp[w];
    for (i = 0; i < w; i++) {
        int offset = srcStride * -1 + i;
        int val = (src[offset - 1] - 12 * src[offset] - 6 * src[offset + 1] + src[offset + 2]
                 - 6 * src[i - 1] + 72 * src[i] + 36 * src[i + 1] - 6 * src[i + 2]
                 - 12 * src[srcStride + i - 1] + 144 * src[srcStride + i] + 72 * src[srcStride + i + 1] - 12 * src[srcStride + i + 2]
                 + src[2*srcStride + i - 1] - 12 * src[2*srcStride + i] - 6 * src[2*srcStride + i + 1] + src[2*srcStride + i + 2] + 128) >> 8;
        temp[i] = cm[val];
    }
    for (i = 0; i < w; i++) {
        dst[i] = temp[i];
    }
    src += srcStride;
    dst += dstStride;
}
}
