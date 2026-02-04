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
        uint8_t temp1 = (src[0] * 3 + src[srcStride]) >> 2;
        uint8_t temp2 = (src[0] + 3 * src[srcStride]) >> 2;
        dst[0] = temp1;
        dst[dstStride] = temp2;
    }
    for (x = mmxSize - 1; x < srcWidth - 1; x++) {
        uint8_t valA = (3 * src[x + 0] + src[x + srcStride + 1]) >> 2;
        uint8_t valB = (src[x + 0] + 3 * src[x + srcStride + 1]) >> 2;
        uint8_t valC = (src[x + 1] + 3 * src[x + srcStride]) >> 2;
        uint8_t valD = (3 * src[x + 1] + src[x + srcStride]) >> 2;

        dst[2 * x + 1] = valA;
        dst[2 * x + dstStride + 2] = valB;
        dst[2 * x + dstStride + 1] = valC;
        dst[2 * x + 2] = valD;
    }
    uint8_t lastIdx = srcWidth - 1;
    uint8_t finalA = (3 * src[lastIdx] + src[lastIdx + srcStride]) >> 2;
    uint8_t finalB = (src[lastIdx] + 3 * src[lastIdx + srcStride]) >> 2;
    dst[srcWidth * 2 - 1] = finalA;
    dst[srcWidth * 2 - 1 + dstStride] = finalB;
    dst += dstStride * 2;
    src += srcStride;
}
}
