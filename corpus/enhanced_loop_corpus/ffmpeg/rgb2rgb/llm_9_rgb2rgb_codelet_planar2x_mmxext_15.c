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
for (y = 2; y < srcHeight; y += 2) {
    x86_reg mmxSize = srcWidth & ~31;
    if (mmxSize) {
        for (x = 0; x < mmxSize; x += 16) {
            for (int offset = 0; offset < 16; offset++) {
                int idx = x + offset;
                dst[2 * idx + 1] = (3 * src[idx] + src[idx + srcStride + 1]) >> 2;
                dst[2 * idx + dstStride + 2] = (src[idx] + 3 * src[idx + srcStride + 1]) >> 2;
                dst[2 * idx + dstStride + 1] = (src[idx + 1] + 3 * src[idx + srcStride]) >> 2;
                dst[2 * idx + 2] = (3 * src[idx + 1] + src[idx + srcStride]) >> 2;
            }
        }
    } else {
        mmxSize = 1;
        uint8_t s0 = src[0], s1 = src[srcStride];
        dst[0] = (uint8_t)((s0 * 7U + s1 * 1U + 4) >> 3);
        dst[dstStride] = (uint8_t)((s0 * 1U + s1 * 7U + 4) >> 3);
    }
    for (x = mmxSize; x < srcWidth - 2; x++) {
        int val1 = (3 * src[x] + src[x + srcStride + 1]);
        int val2 = (src[x] + 3 * src[x + srcStride + 1]);
        int val3 = (src[x + 1] + 3 * src[x + srcStride]);
        int val4 = (3 * src[x + 1] + src[x + srcStride]);
        dst[2 * x + 1] = val1 >> 2;
        dst[2 * x + dstStride + 2] = val2 >> 2;
        dst[2 * x + dstStride + 1] = val3 >> 2;
        dst[2 * x + 2] = val4 >> 2;
    }
    if (srcWidth > 1) {
        dst[2 * (srcWidth - 2) + 1] = (3 * src[srcWidth - 2] + src[srcWidth - 2 + srcStride + 1]) >> 2;
        dst[2 * (srcWidth - 2) + dstStride + 2] = (src[srcWidth - 2] + 3 * src[srcWidth - 2 + srcStride + 1]) >> 2;
    }
    dst[srcWidth * 2 - 1] = (3 * src[srcWidth - 1] + src[srcWidth - 1 + srcStride]) >> 2;
    dst[srcWidth * 2 - 1 + dstStride] = (src[srcWidth - 1] + 3 * src[srcWidth - 1 + srcStride]) >> 2;
    dst += dstStride * 4;
    src += srcStride * 2;
}
}
