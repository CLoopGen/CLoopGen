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
        int index = (src[srcStride * -1 + i - 1] - 12 * src[srcStride * -1 + i + 1] - 6 * src[srcStride * -1 + i] + src[srcStride * -1 + i + 2]
                   - 12 * src[srcStride * 0 + i - 1] + 144 * src[srcStride * 0 + i + 1] + 72 * src[srcStride * 0 + i] - 12 * src[srcStride * 0 + i + 2]
                   - 6 * src[srcStride * 1 + i - 1] + 72 * src[srcStride * 1 + i + 1] + 36 * src[srcStride * 1 + i] - 6 * src[srcStride * 1 + i + 2]
                   + src[srcStride * 2 + i - 1] - 12 * src[srcStride * 2 + i + 1] - 6 * src[srcStride * 2 + i] + src[srcStride * 2 + i + 2] + 128) >> 8;
        temp[i] = cm[index];
    }
    for (i = 0; i < w; i++) {
        dst[i] = ((dst[i] + temp[i] + 1) >> 1);
    }
    src += srcStride;
    dst += dstStride;
}
}
