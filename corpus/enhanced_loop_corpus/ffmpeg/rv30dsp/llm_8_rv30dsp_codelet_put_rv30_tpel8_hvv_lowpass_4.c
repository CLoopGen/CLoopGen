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
        int offset = srcStride * -1 + i;
        dst[i] = cm[(src[offset - 1] + 3 * src[offset] - src[offset + 1] + 
                     2 * src[srcStride * 0 + i - 1] + 8 * src[srcStride * 0 + i] + 2 * src[srcStride * 0 + i + 1] +
                     src[srcStride * 1 + i - 1] + 3 * src[srcStride * 1 + i] - src[srcStride * 1 + i + 1] + 64) >> 7];
        if (i + 1 < w) {
            offset = srcStride * -1 + i + 1;
            dst[i + 1] = cm[(src[offset - 1] + 3 * src[offset] - src[offset + 1] + 
                             2 * src[srcStride * 0 + i] + 8 * src[srcStride * 0 + i + 1] + 2 * src[srcStride * 0 + i + 2] +
                             src[srcStride * 1 + i] + 3 * src[srcStride * 1 + i + 1] - src[srcStride * 1 + i + 2] + 64) >> 7];
        }
    }
    src += srcStride;
    dst += dstStride;
}
}
