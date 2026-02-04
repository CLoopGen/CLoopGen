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
        if (j < h) {
            dst[i] = (((dst[i]) + cm[(src[srcStride * -1 + i - 1] - 12 * src[srcStride * -1 + i] - 6 * src[srcStride * -1 + i + 1] + src[srcStride * -1 + i + 2] + -12 * src[srcStride * 0 + i - 1] + 144 * src[srcStride * 0 + i] + 72 * src[srcStride * 0 + i + 1] - 12 * src[srcStride * 0 + i + 2] + -6 * src[srcStride * 1 + i - 1] + 72 * src[srcStride * 1 + i] + 36 * src[srcStride * 1 + i + 1] - 6 * src[srcStride * 1 + i + 2] + src[srcStride * 2 + i - 1] - 12 * src[srcStride * 2 + i] - 6 * src[srcStride * 2 + i + 1] + src[srcStride * 2 + i + 2] + 128) >> 8] + 1) >> 1);
        }
        if (j + 1 < h) {
            dst[dstStride + i] = (((dst[dstStride + i]) + cm[(src[srcStride * 0 + i - 1] - 12 * src[srcStride * 0 + i] - 6 * src[srcStride * 0 + i + 1] + src[srcStride * 0 + i + 2] + -12 * src[srcStride * 1 + i - 1] + 144 * src[srcStride * 1 + i] + 72 * src[srcStride * 1 + i + 1] - 12 * src[srcStride * 1 + i + 2] + -6 * src[srcStride * 2 + i - 1] + 72 * src[srcStride * 2 + i] + 36 * src[srcStride * 2 + i + 1] - 6 * src[srcStride * 2 + i + 2] + src[srcStride * 3 + i - 1] - 12 * src[srcStride * 3 + i] - 6 * src[srcStride * 3 + i + 1] + src[srcStride * 3 + i + 2] + 128) >> 8] + 1) >> 1);
        }
    }
    src += 2 * srcStride;
    dst += 2 * dstStride;
}
}
