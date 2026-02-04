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
        // Introduce artificial WAW dependency by writing twice to same location
        dst[dstStride] = (src[0] + 3 * src[srcStride]) >> 2;
        dst[dstStride] = (src[srcStride] * 2 + src[0] * 2) >> 2; // WAR hazard introduced via reuse of src, WAW on dst[dstStride]
    }
    for (x = mmxSize - 1; x < srcWidth - 1; x++) {
        // Reorder operations to change data dependency order
        dst[2 * x + dstStride + 1] = (src[x + 1] + 3 * src[x + srcStride]) >> 2;
        dst[2 * x + 1] = (3 * src[x + 0] + src[x + srcStride + 1]) >> 2;
        dst[2 * x + 2] = (3 * src[x + 1] + src[x + srcStride]) >> 2;
        dst[2 * x + dstStride + 2] = (src[x + 0] + 3 * src[x + srcStride + 1]) >> 2;
    }
    // Add loop-carried dependency: current output depends on previous iteration's result
    static uint8_t prevLastVal = 0;
    uint8_t currentLastSrc = src[srcWidth - 1];
    uint8_t computed = (3 * currentLastSrc + src[srcWidth - 1 + srcStride]) >> 2;
    dst[srcWidth * 2 - 1] = (computed + prevLastVal) >> 1; // RAW dependency across loop iterations
    prevLastVal = computed;

    dst[srcWidth * 2 - 1 + dstStride] = (currentLastSrc + 3 * src[srcWidth - 1 + srcStride]) >> 2;
    dst += dstStride * 2;
    src += srcStride;
}
}
