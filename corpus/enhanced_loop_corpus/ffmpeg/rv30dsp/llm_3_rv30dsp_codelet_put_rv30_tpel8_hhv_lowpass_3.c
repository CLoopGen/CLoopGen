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
        uint8_t *src_p = src;
        uint8_t *dst_p = dst;
        // Unroll and access four elements consecutively to promote vectorization
        dst_p[i+0] = cm[(
            src_p[srcStride * -1 + i+0 - 1] - 12 * src_p[srcStride * -1 + i+0 + 1] - 6 * src_p[srcStride * -1 + i+0] + src_p[srcStride * -1 + i+0 + 2] +
            -12 * src_p[srcStride * 0 + i+0 - 1] + 144 * src_p[srcStride * 0 + i+0 + 1] + 72 * src_p[srcStride * 0 + i+0] - 12 * src_p[srcStride * 0 + i+0 + 2] +
            -6 * src_p[srcStride * 1 + i+0 - 1] + 72 * src_p[srcStride * 1 + i+0 + 1] + 36 * src_p[srcStride * 1 + i+0] - 6 * src_p[srcStride * 1 + i+0 + 2] +
            src_p[srcStride * 2 + i+0 - 1] - 12 * src_p[srcStride * 2 + i+0 + 1] - 6 * src_p[srcStride * 2 + i+0] + src_p[srcStride * 2 + i+0 + 2] + 128) >> 8];

        dst_p[i+1] = cm[(
            src_p[srcStride * -1 + i+1 - 1] - 12 * src_p[srcStride * -1 + i+1 + 1] - 6 * src_p[srcStride * -1 + i+1] + src_p[srcStride * -1 + i+1 + 2] +
            -12 * src_p[srcStride * 0 + i+1 - 1] + 144 * src_p[srcStride * 0 + i+1 + 1] + 72 * src_p[srcStride * 0 + i+1] - 12 * src_p[srcStride * 0 + i+1 + 2] +
            -6 * src_p[srcStride * 1 + i+1 - 1] + 72 * src_p[srcStride * 1 + i+1 + 1] + 36 * src_p[srcStride * 1 + i+1] - 6 * src_p[srcStride * 1 + i+1 + 2] +
            src_p[srcStride * 2 + i+1 - 1] - 12 * src_p[srcStride * 2 + i+1 + 1] - 6 * src_p[srcStride * 2 + i+1] + src_p[srcStride * 2 + i+1 + 2] + 128) >> 8];

        dst_p[i+2] = cm[(
            src_p[srcStride * -1 + i+2 - 1] - 12 * src_p[srcStride * -1 + i+2 + 1] - 6 * src_p[srcStride * -1 + i+2] + src_p[srcStride * -1 + i+2 + 2] +
            -12 * src_p[srcStride * 0 + i+2 - 1] + 144 * src_p[srcStride * 0 + i+2 + 1] + 72 * src_p[srcStride * 0 + i+2] - 12 * src_p[srcStride * 0 + i+2 + 2] +
            -6 * src_p[srcStride * 1 + i+2 - 1] + 72 * src_p[srcStride * 1 + i+2 + 1] + 36 * src_p[srcStride * 1 + i+2] - 6 * src_p[srcStride * 1 + i+2 + 2] +
            src_p[srcStride * 2 + i+2 - 1] - 12 * src_p[srcStride * 2 + i+2 + 1] - 6 * src_p[srcStride * 2 + i+2] + src_p[srcStride * 2 + i+2 + 2] + 128) >> 8];

        dst_p[i+3] = cm[(
            src_p[srcStride * -1 + i+3 - 1] - 12 * src_p[srcStride * -1 + i+3 + 1] - 6 * src_p[srcStride * -1 + i+3] + src_p[srcStride * -1 + i+3 + 2] +
            -12 * src_p[srcStride * 0 + i+3 - 1] + 144 * src_p[srcStride * 0 + i+3 + 1] + 72 * src_p[srcStride * 0 + i+3] - 12 * src_p[srcStride * 0 + i+3 + 2] +
            -6 * src_p[srcStride * 1 + i+3 - 1] + 72 * src_p[srcStride * 1 + i+3 + 1] + 36 * src_p[srcStride * 1 + i+3] - 6 * src_p[srcStride * 1 + i+3 + 2] +
            src_p[srcStride * 2 + i+3 - 1] - 12 * src_p[srcStride * 2 + i+3 + 1] - 6 * src_p[srcStride * 2 + i+3] + src_p[srcStride * 2 + i+3 + 2] + 128) >> 8];
    }
    // Handle remaining elements if w is not a multiple of 4
    for (; i < w; i++) {
        dst[i] = cm[(
            src[srcStride * -1 + i - 1] - 12 * src[srcStride * -1 + i + 1] - 6 * src[srcStride * -1 + i] + src[srcStride * -1 + i + 2] +
            -12 * src[srcStride * 0 + i - 1] + 144 * src[srcStride * 0 + i + 1] + 72 * src[srcStride * 0 + i] - 12 * src[srcStride * 0 + i + 2] +
            -6 * src[srcStride * 1 + i - 1] + 72 * src[srcStride * 1 + i + 1] + 36 * src[srcStride * 1 + i] - 6 * src[srcStride * 1 + i + 2] +
            src[srcStride * 2 + i - 1] - 12 * src[srcStride * 2 + i + 1] - 6 * src[srcStride * 2 + i] + src[srcStride * 2 + i + 2] + 128) >> 8];
    }
    src += srcStride;
    dst += dstStride;
}
}
