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
    for (i = 0; i < w; i += 2) {
        int val1 = src[srcStride * -1 + i - 1] - 12 * src[srcStride * -1 + i] - 6 * src[srcStride * -1 + i + 1] + src[srcStride * -1 + i + 2];
        int val2 = -6 * src[srcStride * 0 + i - 1] + 72 * src[srcStride * 0 + i] + 36 * src[srcStride * 0 + i + 1] - 6 * src[srcStride * 0 + i + 2];
        int val3 = -12 * src[srcStride * 1 + i - 1] + 144 * src[srcStride * 1 + i] + 72 * src[srcStride * 1 + i + 1] - 12 * src[srcStride * 1 + i + 2];
        int val4 = src[srcStride * 2 + i - 1] - 12 * src[srcStride * 2 + i] - 6 * src[srcStride * 2 + i + 1] + src[srcStride * 2 + i + 2];
        int sum = (val1 + val2 + val3 + val4 + 128) >> 8;
        dst[i] = (dst[i] + cm[sum] + 1) >> 1;
        if (i + 1 < w) {
            dst[i + 1] = (dst[i + 1] + cm[(src[srcStride * -1 + i] - 12 * src[srcStride * -1 + i + 1] - 6 * src[srcStride * -1 + i + 2] + src[srcStride * -1 + i + 3] + 
                                           -6 * src[srcStride * 0 + i] + 72 * src[srcStride * 0 + i + 1] + 36 * src[srcStride * 0 + i + 2] - 6 * src[srcStride * 0 + i + 3] + 
                                           -12 * src[srcStride * 1 + i] + 144 * src[srcStride * 1 + i + 1] + 72 * src[srcStride * 1 + i + 2] - 12 * src[srcStride * 1 + i + 3] + 
                                           src[srcStride * 2 + i] - 12 * src[srcStride * 2 + i + 1] - 6 * src[srcStride * 2 + i + 2] + src[srcStride * 2 + i + 3] + 128) >> 8] + 1) >> 1;
        }
    }
    src += srcStride;
    dst += dstStride;
}
}
