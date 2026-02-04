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
for (y = 2; y < srcHeight - 1; y++) {
    const int mmxSize = 1;
    dst[0] = (src[0] * 5 + 2 * src[srcStride] + src[2 * srcStride]) >> 3;
    dst[dstStride] = (src[0] + 2 * src[srcStride] + 5 * src[2 * srcStride]) >> 3;
    for (x = mmxSize; x < srcWidth - 2; x++) {
        dst[2 * x + 1] = (src[x] * 4 + src[x + srcStride + 1] + src[x + 2 * srcStride + 1]) >> 3;
        dst[2 * x + dstStride + 2] = (src[x] + 4 * src[x + srcStride + 1] + src[x + 2 * srcStride + 1]) >> 3;
        dst[2 * x + dstStride + 1] = (src[x + 1] + 4 * src[x + srcStride] + src[x + 2 * srcStride]) >> 3;
        dst[2 * x + 2] = (src[x + 1] * 4 + src[x + srcStride] + src[x + 2 * srcStride]) >> 3;
    }
    dst[srcWidth * 2 - 1] = (src[srcWidth - 1] * 5 + 2 * src[srcWidth - 1 + srcStride] + src[srcWidth - 1 + 2 * srcStride]) >> 3;
    dst[srcWidth * 2 - 1 + dstStride] = (src[srcWidth - 1] + 2 * src[srcWidth - 1 + srcStride] + 5 * src[srcWidth - 1 + 2 * srcStride]) >> 3;
    dst += dstStride * 2;
    src += srcStride;
}
}
