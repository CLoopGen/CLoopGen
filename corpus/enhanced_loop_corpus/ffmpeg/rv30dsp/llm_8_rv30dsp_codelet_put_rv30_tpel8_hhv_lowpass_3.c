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
        int offset1 = srcStride * -1 + i - 1;
        int offset2 = srcStride * 0 + i - 1;
        int offset3 = srcStride * 1 + i - 1;
        int offset4 = srcStride * 2 + i - 1;
        dst[i] = cm[(src[offset1] - 12 * src[offset1 + 2] - 6 * src[offset1 + 1] + src[offset1 + 3] 
                   - 12 * src[offset2] + 144 * src[offset2 + 2] + 72 * src[offset2 + 1] - 12 * src[offset2 + 3]
                   - 6 * src[offset3] + 72 * src[offset3 + 2] + 36 * src[offset3 + 1] - 6 * src[offset3 + 3]
                   + src[offset4] - 12 * src[offset4 + 2] - 6 * src[offset4 + 1] + src[offset4 + 3] + 128) >> 8];
        if (i + 1 < w) {
            dst[i+1] = cm[(src[srcStride * -1 + i] - 12 * src[srcStride * -1 + i + 2] - 6 * src[srcStride * -1 + i + 1] + src[srcStride * -1 + i + 3]
                         - 12 * src[srcStride * 0 + i] + 144 * src[srcStride * 0 + i + 2] + 72 * src[srcStride * 0 + i + 1] - 12 * src[srcStride * 0 + i + 3]
                         - 6 * src[srcStride * 1 + i] + 72 * src[srcStride * 1 + i + 2] + 36 * src[srcStride * 1 + i + 1] - 6 * src[srcStride * 1 + i + 3]
                         + src[srcStride * 2 + i] - 12 * src[srcStride * 2 + i + 2] - 6 * src[srcStride * 2 + i + 1] + src[srcStride * 2 + i + 3] + 128) >> 8];
        }
    }
    src += srcStride;
    dst += dstStride;
}
}
