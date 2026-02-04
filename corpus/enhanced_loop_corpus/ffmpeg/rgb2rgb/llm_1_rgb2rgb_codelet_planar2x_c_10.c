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
    for (int step = 0; step < 2; step++) {
        if (step == 0) {
            dst[0] = (src[0] * 3 + src[srcStride]) >> 2;
            for (x = mmxSize - 1; x < srcWidth - 1; x++) {
                dst[2 * x + 1] = (src[x + 0] * 3 + src[x + srcStride + 1]) >> 2;
                dst[2 * x + dstStride + 1] = (src[x + 1] + 3 * src[x + srcStride]) >> 2;
            }
            dst[srcWidth * 2 - 1] = (src[srcWidth - 1] * 3 + src[srcWidth - 1 + srcStride]) >> 2;
        } else {
            dst[dstStride] = (src[0] + 3 * src[srcStride]) >> 2;
            for (x = mmxSize - 1; x < srcWidth - 1; x++) {
                dst[2 * x + dstStride + 2] = (src[x + 0] + 3 * src[x + srcStride + 1]) >> 2;
                dst[2 * x + 2] = (src[x + 1] * 3 + src[x + srcStride]) >> 2;
            }
            dst[srcWidth * 2 - 1 + dstStride] = (src[srcWidth - 1] + 3 * src[srcWidth - 1 + srcStride]) >> 2;
        }
    }
    dst += dstStride * 2;
    src += srcStride;
}
}
