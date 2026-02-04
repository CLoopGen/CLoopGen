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
    if (j + 1 < h) {
        for (i = 0; i < w; i++) {
            int base_src = srcStride * j;
            int base_dst = dstStride * j;
            
            // First row computation
            int s0 = src[srcStride * -1 + i - 1] - 12 * src[srcStride * -1 + i] - 6 * src[srcStride * -1 + i + 1] + src[srcStride * -1 + i + 2];
            int s1 = -12 * src[i - 1] + 144 * src[i] + 72 * src[i + 1] - 12 * src[i + 2];
            int s2 = -6 * src[srcStride + i - 1] + 72 * src[srcStride + i] + 36 * src[srcStride + i + 1] - 6 * src[srcStride + i + 2];
            int s3 = src[2*srcStride + i - 1] - 12 * src[2*srcStride + i] - 6 * src[2*srcStride + i + 1] + src[2*srcStride + i + 2];
            dst[i] = cm[(s0 + s1 + s2 + s3 + 128) >> 8];

            // Second row using shifted reference (j+1 as center)
            int t0 = src[i - 1] - 12 * src[i] - 6 * src[i + 1] + src[i + 2];
            int t1 = -12 * src[srcStride + i - 1] + 144 * src[srcStride + i] + 72 * src[srcStride + i + 1] - 12 * src[srcStride + i + 2];
            int t2 = -6 * src[2*srcStride + i - 1] + 72 * src[2*srcStride + i] + 36 * src[2*srcStride + i + 1] - 6 * src[2*srcStride + i + 2];
            int t3 = src[3*srcStride + i - 1] - 12 * src[3*srcStride + i] - 6 * src[3*srcStride + i + 1] + src[3*srcStride + i + 2];
            dst[dstStride + i] = cm[(t0 + t1 + t2 + t3 + 128) >> 8];
        }
        src += 2 * srcStride;
        dst += 2 * dstStride;
    } else {
        // Handle odd-height case: last single row
        for (i = 0; i < w; i++) {
            dst[i] = cm[(src[srcStride * -1 + i - 1] - 12 * src[srcStride * -1 + i] - 6 * src[srcStride * -1 + i + 1] + src[srcStride * -1 + i + 2] +
                         -12 * src[i - 1] + 144 * src[i] + 72 * src[i + 1] - 12 * src[i + 2] +
                         -6 * src[srcStride + i - 1] + 72 * src[srcStride + i] + 36 * src[srcStride + i + 1] - 6 * src[srcStride + i + 2] +
                         src[2*srcStride + i - 1] - 12 * src[2*srcStride + i] - 6 * src[2*srcStride + i + 1] + src[2*srcStride + i + 2] + 128) >> 8];
        }
        src += srcStride;
        dst += dstStride;
    }
}
}
