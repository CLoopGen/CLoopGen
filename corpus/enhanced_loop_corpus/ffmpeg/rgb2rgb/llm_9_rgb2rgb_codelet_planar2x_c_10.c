#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int srcWidth;
extern int srcHeight;
extern int srcStride;
extern int dstStride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < srcHeight; y += 2) {
    const int mmxSize = 1;
    dst[0] = (src[0] * 2 + src[srcStride]) >> 2;
    dst[dstStride] = (src[0] + 2 * src[srcStride]) >> 2;
    for (x = mmxSize - 1; x < srcWidth - 1; x += 2) {
        int idx1 = x, idx2 = x + 1;
        dst[2 * idx1 + 1] = (src[idx1] * 3 + src[idx1 + srcStride + 1]) >> 2;
        dst[2 * idx1 + dstStride + 2] = (src[idx1] + 3 * src[idx1 + srcStride + 1]) >> 2;
        dst[2 * idx1 + dstStride + 1] = (src[idx1 + 1] + 3 * src[idx1 + srcStride]) >> 2;
        dst[2 * idx1 + 2] = (src[idx1 + 1] * 3 + src[idx1 + srcStride]) >> 2;

        if (idx2 < srcWidth - 1) {
            dst[2 * idx2 + 1] = (src[idx2] * 3 + src[idx2 + srcStride + 1]) >> 2;
            dst[2 * idx2 + dstStride + 2] = (src[idx2] + 3 * src[idx2 + srcStride + 1]) >> 2;
            dst[2 * idx2 + dstStride + 1] = (src[idx2 + 1] + 3 * src[idx2 + srcStride]) >> 2;
            dst[2 * idx2 + 2] = (src[idx2 + 1] * 3 + src[idx2 + srcStride]) >> 2;
        }
    }
    dst[srcWidth * 2 - 1] = (src[srcWidth - 1] * 2 + src[srcWidth - 1 + srcStride]) >> 2;
    dst[srcWidth * 2 - 1 + dstStride] = (src[srcWidth - 1] + 2 * src[srcWidth - 1 + srcStride]) >> 2;
    dst += dstStride * 2;
    src += srcStride;
}
}
