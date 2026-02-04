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
        int base_idx = srcStride * -1 + i;
        uint8_t val0 = cm[(src[base_idx - 1] - 12 * src[base_idx] - 6 * src[base_idx + 1] + src[base_idx + 2] 
                         - 12 * src[i - 1] + 144 * src[i] + 72 * src[i + 1] - 12 * src[i + 2]
                         - 6 * src[srcStride + i - 1] + 72 * src[srcStride + i] + 36 * src[srcStride + i + 1] - 6 * src[srcStride + i + 2]
                         + src[2*srcStride + i - 1] - 12 * src[2*srcStride + i] - 6 * src[2*srcStride + i + 1] + src[2*srcStride + i + 2] + 128) >> 8];
        uint8_t val1 = cm[(src[base_idx + 0] - 12 * src[base_idx + 1] - 6 * src[base_idx + 2] + src[base_idx + 3] 
                         - 12 * src[i + 0] + 144 * src[i + 1] + 72 * src[i + 2] - 12 * src[i + 3]
                         - 6 * src[srcStride + i + 0] + 72 * src[srcStride + i + 1] + 36 * src[srcStride + i + 2] - 6 * src[srcStride + i + 3]
                         + src[2*srcStride + i + 0] - 12 * src[2*srcStride + i + 1] - 6 * src[2*srcStride + i + 2] + src[2*srcStride + i + 3] + 128) >> 8];
        uint8_t val2 = cm[(src[base_idx + 1] - 12 * src[base_idx + 2] - 6 * src[base_idx + 3] + src[base_idx + 4] 
                         - 12 * src[i + 1] + 144 * src[i + 2] + 72 * src[i + 3] - 12 * src[i + 4]
                         - 6 * src[srcStride + i + 1] + 72 * src[srcStride + i + 2] + 36 * src[srcStride + i + 3] - 6 * src[srcStride + i + 4]
                         + src[2*srcStride + i + 1] - 12 * src[2*srcStride + i + 2] - 6 * src[2*srcStride + i + 3] + src[2*srcStride + i + 4] + 128) >> 8];
        uint8_t val3 = cm[(src[base_idx + 2] - 12 * src[base_idx + 3] - 6 * src[base_idx + 4] + src[base_idx + 5] 
                         - 12 * src[i + 2] + 144 * src[i + 3] + 72 * src[i + 4] - 12 * src[i + 5]
                         - 6 * src[srcStride + i + 2] + 72 * src[srcStride + i + 3] + 36 * src[srcStride + i + 4] - 6 * src[srcStride + i + 5]
                         + src[2*srcStride + i + 2] - 12 * src[2*srcStride + i + 3] - 6 * src[2*srcStride + i + 4] + src[2*srcStride + i + 5] + 128) >> 8];

        dst[i]     = ((dst[i]     + val0 + 1) >> 1);
        dst[i + 1] = ((dst[i + 1] + val1 + 1) >> 1);
        dst[i + 2] = ((dst[i + 2] + val2 + 1) >> 1);
        dst[i + 3] = ((dst[i + 3] + val3 + 1) >> 1);
    }
    // Handle remaining elements if w is not a multiple of 4
    for (; i < w; i++) {
        dst[i] = (((dst[i]) + cm[(src[srcStride * -1 + i - 1] - 12 * src[srcStride * -1 + i] - 6 * src[srcStride * -1 + i + 1] + src[srcStride * -1 + i + 2] 
                                - 12 * src[i - 1] + 144 * src[i] + 72 * src[i + 1] - 12 * src[i + 2]
                                - 6 * src[srcStride + i - 1] + 72 * src[srcStride + i] + 36 * src[srcStride + i + 1] - 6 * src[srcStride + i + 2]
                                + src[2*srcStride + i - 1] - 12 * src[2*srcStride + i] - 6 * src[2*srcStride + i + 1] + src[2*srcStride + i + 2] + 128) >> 8] + 1) >> 1);
    }
    src += srcStride;
    dst += dstStride;
}
}
