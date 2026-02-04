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
            for (int k = 0; k < 16; k += 4) {
                int idx = x + k;
                dst[2*idx + 1] = (3 * src[idx] + src[idx + srcStride + 1]) >> 2;
                dst[2*idx + dstStride + 2] = (src[idx] + 3 * src[idx + srcStride + 1]) >> 2;
                dst[2*idx + dstStride + 1] = (src[idx+1] + 3 * src[idx + srcStride]) >> 2;
                dst[2*idx + 2] = (3 * src[idx+1] + src[idx + srcStride]) >> 2;

                dst[2*(idx+2) + 1] = (3 * src[idx+2] + src[idx + srcStride + 3]) >> 2;
                dst[2*(idx+2) + dstStride + 2] = (src[idx+2] + 3 * src[idx + srcStride + 3]) >> 2;
                dst[2*(idx+2) + dstStride + 1] = (src[idx+3] + 3 * src[idx + srcStride + 2]) >> 2;
                dst[2*(idx+2) + 2] = (3 * src[idx+3] + src[idx + srcStride + 2]) >> 2;
            }
        }
    } else {
        mmxSize = 1;
        dst[0] = (src[0]*7 + src[srcStride]) >> 3;
        dst[dstStride] = (src[0] + 7*src[srcStride]) >> 3;
    }
    for (x = mmxSize; x < srcWidth - 2; x++) {
        dst[2*x + 1] = (src[x] + src[x + srcStride + 1] + src[x] + src[x]) >> 2;
        dst[2*x + dstStride + 2] = (src[x] + src[x + srcStride + 1] + src[x + srcStride + 1] + src[x + srcStride + 1]) >> 2;
        dst[2*x + dstStride + 1] = (src[x+1] + src[x + srcStride] + src[x + srcStride] + src[x + srcStride]) >> 2;
        dst[2*x + 2] = (src[x+1] + src[x+1] + src[x+1] + src[x + srcStride]) >> 2;
    }
    dst[srcWidth * 2 - 1] = (3 * src[srcWidth - 1] + src[srcWidth - 1 + srcStride]) >> 2;
    dst[srcWidth * 2 - 1 + dstStride] = (src[srcWidth - 1] + 3 * src[srcWidth - 1 + srcStride]) >> 2;
    dst += 2 * dstStride;
    src += 2 * srcStride;
}
}
