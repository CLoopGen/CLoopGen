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
    for (i = 0; i < w - 3; i += 4) {
        int idx0 = (src[srcStride * -1 + i - 1] - 12 * src[srcStride * -1 + i] - 6 * src[srcStride * -1 + i + 1] + src[srcStride * -1 + i + 2] 
                  - 6 * src[srcStride * 0 + i - 1] + 72 * src[srcStride * 0 + i] + 36 * src[srcStride * 0 + i + 1] - 6 * src[srcStride * 0 + i + 2] 
                  - 12 * src[srcStride * 1 + i - 1] + 144 * src[srcStride * 1 + i] + 72 * src[srcStride * 1 + i + 1] - 12 * src[srcStride * 1 + i + 2] 
                  + src[srcStride * 2 + i - 1] - 12 * src[srcStride * 2 + i] - 6 * src[srcStride * 2 + i + 1] + src[srcStride * 2 + i + 2] + 128) >> 8;
        int idx1 = (src[srcStride * -1 + i] - 12 * src[srcStride * -1 + i + 1] - 6 * src[srcStride * -1 + i + 2] + src[srcStride * -1 + i + 3] 
                  - 6 * src[srcStride * 0 + i] + 72 * src[srcStride * 0 + i + 1] + 36 * src[srcStride * 0 + i + 2] - 6 * src[srcStride * 0 + i + 3] 
                  - 12 * src[srcStride * 1 + i - 0] + 144 * src[srcStride * 1 + i + 1] + 72 * src[srcStride * 1 + i + 2] - 12 * src[srcStride * 1 + i + 3] 
                  + src[srcStride * 2 + i] - 12 * src[srcStride * 2 + i + 1] - 6 * src[srcStride * 2 + i + 2] + src[srcStride * 2 + i + 3] + 128) >> 8;
        int idx2 = (src[srcStride * -1 + i + 1] - 12 * src[srcStride * -1 + i + 2] - 6 * src[srcStride * -1 + i + 3] + src[srcStride * -1 + i + 4] 
                  - 6 * src[srcStride * 0 + i + 1] + 72 * src[srcStride * 0 + i + 2] + 36 * src[srcStride * 0 + i + 3] - 6 * src[srcStride * 0 + i + 4] 
                  - 12 * src[srcStride * 1 + i + 1] + 144 * src[srcStride * 1 + i + 2] + 72 * src[srcStride * 1 + i + 3] - 12 * src[srcStride * 1 + i + 4] 
                  + src[srcStride * 2 + i + 1] - 12 * src[srcStride * 2 + i + 2] - 6 * src[srcStride * 2 + i + 3] + src[srcStride * 2 + i + 4] + 128) >> 8;
        int idx3 = (src[srcStride * -1 + i + 2] - 12 * src[srcStride * -1 + i + 3] - 6 * src[srcStride * -1 + i + 4] + src[srcStride * -1 + i + 5] 
                  - 6 * src[srcStride * 0 + i + 2] + 72 * src[srcStride * 0 + i + 3] + 36 * src[srcStride * 0 + i + 4] - 6 * src[srcStride * 0 + i + 5] 
                  - 12 * src[srcStride * 1 + i + 2] + 144 * src[srcStride * 1 + i + 3] + 72 * src[srcStride * 1 + i + 4] - 12 * src[srcStride * 1 + i + 5] 
                  + src[srcStride * 2 + i + 2] - 12 * src[srcStride * 2 + i + 3] - 6 * src[srcStride * 2 + i + 4] + src[srcStride * 2 + i + 5] + 128) >> 8;

        dst[i+0] = ((dst[i+0] + cm[idx0] + 1) >> 1);
        dst[i+1] = ((dst[i+1] + cm[idx1] + 1) >> 1);
        dst[i+2] = ((dst[i+2] + cm[idx2] + 1) >> 1);
        dst[i+3] = ((dst[i+3] + cm[idx3] + 1) >> 1);
    }
    // Handle remaining elements if w is not a multiple of 4
    for (; i < w; i++) {
        dst[i] = (((dst[i]) + cm[(src[srcStride * -1 + i - 1] - 12 * src[srcStride * -1 + i] - 6 * src[srcStride * -1 + i + 1] + src[srcStride * -1 + i + 2] + -6 * src[srcStride * 0 + i - 1] + 72 * src[srcStride * 0 + i] + 36 * src[srcStride * 0 + i + 1] - 6 * src[srcStride * 0 + i + 2] + -12 * src[srcStride * 1 + i - 1] + 144 * src[srcStride * 1 + i] + 72 * src[srcStride * 1 + i + 1] - 12 * src[srcStride * 1 + i + 2] + src[srcStride * 2 + i - 1] - 12 * src[srcStride * 2 + i] - 6 * src[srcStride * 2 + i + 1] + src[srcStride * 2 + i + 2] + 128) >> 8] + 1) >> 1);
    }
    src += srcStride;
    dst += dstStride;
}
}
