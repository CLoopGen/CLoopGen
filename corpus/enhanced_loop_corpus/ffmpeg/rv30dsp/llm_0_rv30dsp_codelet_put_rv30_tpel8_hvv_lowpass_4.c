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
    i = 0;
    while (i < w) {
        dst[i] = cm[(src[srcStride * -1 + i - 1] - 12 * src[srcStride * -1 + i] - 6 * src[srcStride * -1 + i + 1] + src[srcStride * -1 + i + 2] + -6 * src[srcStride * 0 + i - 1] + 72 * src[srcStride * 0 + i] + 36 * src[srcStride * 0 + i + 1] - 6 * src[srcStride * 0 + i + 2] + -12 * src[srcStride * 1 + i - 1] + 144 * src[srcStride * 1 + i] + 72 * src[srcStride * 1 + i + 1] - 12 * src[srcStride * 1 + i + 2] + src[srcStride * 2 + i - 1] - 12 * src[srcStride * 2 + i] - 6 * src[srcStride * 2 + i + 1] + src[srcStride * 2 + i + 2] + 128) >> 8];
        i++;
    }
    src += srcStride;
    dst += dstStride;
}
}
