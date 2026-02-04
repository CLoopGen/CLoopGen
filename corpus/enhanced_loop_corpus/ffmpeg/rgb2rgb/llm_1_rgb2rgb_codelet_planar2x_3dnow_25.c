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
        for (x = mmxSize - 1; x < srcWidth - 1; x++) {
            for (int unroll_factor = 0; unroll_factor < 4 && (x + unroll_factor) < srcWidth - 1; unroll_factor++) {
                int idx = x + unroll_factor;
                dst[2 * idx + 1] = (3 * src[idx + 0] + src[idx + srcStride + 1]) >> 2;
                dst[2 * idx + dstStride + 2] = (src[idx + 0] + 3 * src[idx + srcStride + 1]) >> 2;
                dst[2 * idx + dstStride + 1] = (src[idx + 1] + 3 * src[idx + srcStride]) >> 2;
                dst[2 * idx + 2] = (3 * src[idx + 1] + src[idx + srcStride]) >> 2;
            }
            x += 3; // Advance to avoid redundant work due to inner unrolling
        }
    } else {
        mmxSize = 1;
        dst[0] = (src[0] * 3 + src[srcStride]) >> 2;
        dst[dstStride] = (src[0] + 3 * src[srcStride]) >> 2;
    }
    dst[srcWidth * 2 - 1] = (3 * src[srcWidth - 1] + src[srcWidth - 1 + srcStride]) >> 2;
    dst[srcWidth * 2 - 1 + dstStride] = (src[srcWidth - 1] + 3 * src[srcWidth - 1 + srcStride]) >> 2;
    dst += dstStride * 2;
    src += srcStride;
}
}
