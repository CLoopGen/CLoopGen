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
        int val1 = src[srcStride * -1 + i - 1] - 8 * src[srcStride * -1 + i] + src[srcStride * -1 + i + 1];
        int val2 = src[srcStride * 0 + i - 1] - 8 * src[srcStride * 0 + i] + src[srcStride * 0 + i + 1];
        int val3 = src[srcStride * 1 + i - 1] - 8 * src[srcStride * 1 + i] + src[srcStride * 1 + i + 1];
        int filtered = (val1 + val2 + val3 + 128) >> 8;
        dst[i] = cm[filtered] > 0 ? (cm[filtered] + 1) >> 1 : 0;
        if (i + 1 < w) {
            int val1b = src[srcStride * -1 + i] - 8 * src[srcStride * -1 + i + 1] + src[srcStride * -1 + i + 2];
            int val2b = src[srcStride * 0 + i] - 8 * src[srcStride * 0 + i + 1] + src[srcStride * 0 + i + 2];
            int val3b = src[srcStride * 1 + i] - 8 * src[srcStride * 1 + i + 1] + src[srcStride * 1 + i + 2];
            int filteredb = (val1b + val2b + val3b + 128) >> 8;
            dst[i + 1] = cm[filteredb] > 0 ? (cm[filteredb] + 1) >> 1 : 0;
        }
    }
    src += srcStride;
    dst += dstStride;
}
}
