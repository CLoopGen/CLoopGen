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
        for (x = 0; x < srcWidth - 1; x++) {
            int offset = 2 * x;
            dst[offset + 1] = (3 * src[x] + src[x + srcStride + 1]) >> 2;
            dst[offset + dstStride + 2] = (src[x] + 3 * src[x + srcStride + 1]) >> 2;
        }
        for (x = 0; x < srcWidth - 1; x++) {
            int offset = 2 * x;
            dst[offset + dstStride + 1] = (src[x + 1] + 3 * src[x + srcStride]) >> 2;
            dst[offset + 2] = (3 * src[x + 1] + src[x + srcStride]) >> 2;
        }
    } else {
        mmxSize = 1;
        uint8_t val = (src[0] * 3 + src[srcStride]) >> 2;
        dst[0] = val;
        dst[dstStride] = (src[0] + 3 * src[srcStride]) >> 2;
    }
    int w2 = srcWidth * 2 - 1;
    int swm1 = srcWidth - 1;
    uint8_t contrib1 = (3 * src[swm1] + src[swm1 + srcStride]) >> 2;
    uint8_t contrib2 = (src[swm1] + 3 * src[swm1 + srcStride]) >> 2;
    dst[w2] = contrib1;
    dst[w2 + dstStride] = contrib2;
    dst += dstStride * 2;
    src += srcStride;
}
}
