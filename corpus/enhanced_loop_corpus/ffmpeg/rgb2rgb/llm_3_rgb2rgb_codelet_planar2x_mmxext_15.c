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
for (y = 1; y < srcHeight; y++) {
    x86_reg mmxSize = srcWidth & ~15;
    if (mmxSize) {
    } else {
        mmxSize = 1;
        dst[0] = (src[0] * 3 + src[srcStride]) >> 2;
        dst[dstStride] = (src[0] + 3 * src[srcStride]) >> 2;
    }
    for (x = mmxSize - 1; x < srcWidth - 1; x++) {
        int offset = x;
        dst[2 * offset + 1] = (3 * src[offset] + src[offset + srcStride + 1]) >> 2;
        dst[2 * offset + dstStride + 2] = (src[offset] + 3 * src[offset + srcStride + 1]) >> 2;
        dst[2 * offset + dstStride + 1] = (src[offset + 1] + 3 * src[offset + srcStride]) >> 2;
        dst[2 * offset + 2] = (3 * src[offset + 1] + src[offset + srcStride]) >> 2;
    }
    int finalOffset = srcWidth - 1;
    dst[srcWidth * 2 - 1] = (3 * src[finalOffset] + src[finalOffset + srcStride]) >> 2;
    dst[srcWidth * 2 - 1 + dstStride] = (src[finalOffset] + 3 * src[finalOffset + srcStride]) >> 2;
    dst += dstStride * 2;
    src += srcStride;
}
}
