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
for (y = 1; y < srcHeight; y++) {
    const int mmxSize = 1;
    uint8_t temp1 = src[0];
    uint8_t temp2 = src[srcStride];
    dst[0] = (temp1 * 3 + temp2) >> 2;
    dst[dstStride] = (temp1 + 3 * temp2) >> 2;

    for (x = mmxSize - 1; x < srcWidth - 1; x++) {
        uint8_t a = src[x];
        uint8_t b = src[x + 1];
        uint8_t c = src[x + srcStride];
        uint8_t d = src[x + srcStride + 1];

        dst[2 * x + 1] = (a * 3 + d) >> 2;
        dst[2 * x + dstStride + 2] = (a + 3 * d) >> 2;
        dst[2 * x + dstStride + 1] = (b + 3 * c) >> 2;
        dst[2 * x + 2] = (b * 3 + c) >> 2;
    }

    uint8_t lastSrc = src[srcWidth - 1];
    uint8_t lastSrcBelow = src[srcWidth - 1 + srcStride];
    dst[srcWidth * 2 - 1] = (lastSrc * 3 + lastSrcBelow) >> 2;
    dst[srcWidth * 2 - 1 + dstStride] = (lastSrc + 3 * lastSrcBelow) >> 2;

    dst += dstStride * 2;
    src += srcStride;
}
}
