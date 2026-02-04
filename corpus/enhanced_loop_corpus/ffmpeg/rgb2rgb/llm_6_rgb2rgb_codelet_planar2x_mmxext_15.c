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
        mmxSize = srcWidth;
    } else {
        mmxSize = 1;
        uint8_t temp1 = (src[0] * 3 + src[srcStride]) >> 2;
        uint8_t temp2 = (src[0] + 3 * src[srcStride]) >> 2;
        dst[0] = temp1;
        dst[dstStride] = temp2;
    }
    for (x = mmxSize - 1; x < srcWidth - 1; x++) {
        uint8_t s0 = src[x + 0];
        uint8_t s1 = src[x + 1];
        uint8_t ss0 = src[x + srcStride];
        uint8_t ss1 = src[x + srcStride + 1];

        dst[2 * x + 1] = (3 * s0 + ss1) >> 2;
        dst[2 * x + dstStride + 2] = (s0 + 3 * ss1) >> 2;
        dst[2 * x + dstStride + 1] = (s1 + 3 * ss0) >> 2;
        dst[2 * x + 2] = (3 * s1 + ss0) >> 2;
    }
    uint8_t last_idx = srcWidth - 1;
    uint8_t slast = src[last_idx];
    uint8_t slast_down = src[last_idx + srcStride];
    dst[srcWidth * 2 - 1] = (3 * slast + slast_down) >> 2;
    dst[srcWidth * 2 - 1 + dstStride] = (slast + 3 * slast_down) >> 2;
    dst += dstStride * 2;
    src += srcStride;
}
}
