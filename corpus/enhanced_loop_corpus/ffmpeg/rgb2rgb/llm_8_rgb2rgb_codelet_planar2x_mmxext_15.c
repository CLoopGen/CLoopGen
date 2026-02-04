#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int x86_reg;

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
for (y = 1; y < srcHeight - 1; y++) {
    x86_reg mmxSize = srcWidth & ~7;
    if (mmxSize) {
        for (x = 0; x < mmxSize; x += 8) {
            dst[2 * x + 0] = (3 * src[x + 0] + src[x + srcStride + 0]) >> 2;
            dst[2 * x + 1] = (3 * src[x + 0] + src[x + srcStride + 1]) >> 2;
            dst[2 * x + dstStride + 0] = (src[x + 0] + 3 * src[x + srcStride + 0]) >> 2;
            dst[2 * x + dstStride + 1] = (src[x + 0] + 3 * src[x + srcStride + 1]) >> 2;

            dst[2 * x + 2] = (3 * src[x + 1] + src[x + srcStride + 1]) >> 2;
            dst[2 * x + 3] = (3 * src[x + 1] + src[x + srcStride + 2]) >> 2;
            dst[2 * x + dstStride + 2] = (src[x + 1] + 3 * src[x + srcStride + 1]) >> 2;
            dst[2 * x + dstStride + 3] = (src[x + 1] + 3 * src[x + srcStride + 2]) >> 2;

            dst[2 * x + 4] = (3 * src[x + 2] + src[x + srcStride + 2]) >> 2;
            dst[2 * x + 5] = (3 * src[x + 2] + src[x + srcStride + 3]) >> 2;
            dst[2 * x + dstStride + 4] = (src[x + 2] + 3 * src[x + srcStride + 2]) >> 2;
            dst[2 * x + dstStride + 5] = (src[x + 2] + 3 * src[x + srcStride + 3]) >> 2;

            dst[2 * x + 6] = (3 * src[x + 3] + src[x + srcStride + 3]) >> 2;
            dst[2 * x + 7] = (3 * src[x + 3] + src[x + srcStride + 4]) >> 2;
            dst[2 * x + dstStride + 6] = (src[x + 3] + 3 * src[x + srcStride + 3]) >> 2;
            dst[2 * x + dstStride + 7] = (src[x + 3] + 3 * src[x + srcStride + 4]) >> 2;
        }
    } else {
        mmxSize = 1;
        dst[0] = (src[0] * 5 + 2 * src[srcStride]) / 7;
        dst[dstStride] = (2 * src[0] + 5 * src[srcStride]) / 7;
    }
    for (x = mmxSize - 1; x < srcWidth - 1; x++) {
        int a = src[x], b = src[x + 1], c = src[x + srcStride], d = src[x + srcStride + 1];
        dst[2 * x + 1] = (3*a + d) >> 2;
        dst[2 * x + dstStride + 2] = (a + 3*d) >> 2;
        dst[2 * x + dstStride + 1] = (b + 3*c) >> 2;
        dst[2 * x + 2] = (3*b + c) >> 2;
    }
    dst[srcWidth * 2 - 1] = (3 * src[srcWidth - 1] + src[srcWidth - 1 + srcStride]) >> 2;
    dst[srcWidth * 2 - 1 + dstStride] = (src[srcWidth - 1] + 3 * src[srcWidth - 1 + srcStride]) >> 2;
    dst += dstStride * 2;
    src += srcStride;
}
}
