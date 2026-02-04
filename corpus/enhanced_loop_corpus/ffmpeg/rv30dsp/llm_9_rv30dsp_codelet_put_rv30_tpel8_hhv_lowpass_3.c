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
        int val1 = (src[srcStride * -1 + i - 1] - 12 * src[srcStride * -1 + i + 1] - 6 * src[srcStride * -1 + i] + src[srcStride * -1 + i + 2]
                  - 12 * src[i - 1] + 144 * src[i + 1] + 72 * src[i] - 12 * src[i + 2]
                  - 6 * src[srcStride + i - 1] + 72 * src[srcStride + i + 1] + 36 * src[srcStride + i] - 6 * src[srcStride + i + 2]
                  + src[2*srcStride + i - 1] - 12 * src[2*srcStride + i + 1] - 6 * src[2*srcStride + i] + src[2*srcStride + i + 2] + 128) >> 8;
        dst[i] = cm[val1];

        int val2 = (src[srcStride * -1 + srcStride + i - 1] - 12 * src[srcStride * -1 + srcStride + i + 1] - 6 * src[srcStride * -1 + srcStride + i] + src[srcStride * -1 + srcStride + i + 2]
                  - 12 * src[srcStride + i - 1] + 144 * src[srcStride + i + 1] + 72 * src[srcStride + i] - 12 * src[srcStride + i + 2]
                  - 6 * src[2*srcStride + i - 1] + 72 * src[2*srcStride + i + 1] + 36 * src[2*srcStride + i] - 6 * src[2*srcStride + i + 2]
                  + src[3*srcStride + i - 1] - 12 * src[3*srcStride + i + 1] - 6 * src[3*srcStride + i] + src[3*srcStride + i + 2] + 128) >> 8;
        dst[dstStride + i] = cm[val2];
    }
    src += 2 * srcStride;
    dst += 2 * dstStride;
}
}
