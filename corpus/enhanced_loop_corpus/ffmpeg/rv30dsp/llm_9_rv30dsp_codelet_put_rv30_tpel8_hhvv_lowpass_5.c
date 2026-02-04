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
        if (j + 1 < h) {
            dst[i] = cm[(18 * src[i + srcStride * 0] + 27 * src[i + 1 + srcStride * 0] + 3 * src[i + 2 + srcStride * 0] +
                        27 * src[i + srcStride * 1] + 40 * src[i + 1 + srcStride * 1] + 5 * src[i + 2 + srcStride * 1] +
                        3 * src[i + srcStride * 2] + 5 * src[i + 1 + srcStride * 2] + src[i + 2 + srcStride * 2] + 64) >> 7];
            dst[dstStride + i] = cm[(18 * src[i + srcStride * 1] + 27 * src[i + 1 + srcStride * 1] + 3 * src[i + 2 + srcStride * 1] +
                                   27 * src[i + srcStride * 2] + 40 * src[i + 1 + srcStride * 2] + 5 * src[i + 2 + srcStride * 2] +
                                   3 * src[i + srcStride * 3] + 5 * src[i + 1 + srcStride * 3] + src[i + 2 + srcStride * 3] + 64) >> 7];
        } else {
            dst[i] = cm[(18 * src[i + srcStride * 0] + 27 * src[i + 1 + srcStride * 0] + 3 * src[i + 2 + srcStride * 0] +
                        27 * src[i + srcStride * 1] + 40 * src[i + 1 + srcStride * 1] + 5 * src[i + 2 + srcStride * 1] +
                        3 * src[i + srcStride * 2] + 5 * src[i + 1 + srcStride * 2] + src[i + 2 + srcStride * 2] + 64) >> 7];
        }
    }
    src += 2 * srcStride;
    dst += 2 * dstStride;
}
}
