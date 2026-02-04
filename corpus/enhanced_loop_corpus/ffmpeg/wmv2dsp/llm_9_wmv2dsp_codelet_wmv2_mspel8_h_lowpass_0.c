#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    // Unroll by processing two rows per iteration
    if (i + 1 < h) {
        // First row
        dst[0] = cm[(9 * (src[0] + src[1]) - (src[-1] + src[2]) + 8) >> 4];
        dst[1] = cm[(9 * (src[1] + src[2]) - (src[0] + src[3]) + 8) >> 4];
        dst[2] = cm[(9 * (src[2] + src[3]) - (src[1] + src[4]) + 8) >> 4];
        dst[3] = cm[(9 * (src[3] + src[4]) - (src[2] + src[5]) + 8) >> 4];
        dst[4] = cm[(9 * (src[4] + src[5]) - (src[3] + src[6]) + 8) >> 4];
        dst[5] = cm[(9 * (src[5] + src[6]) - (src[4] + src[7]) + 8) >> 4];
        dst[6] = cm[(9 * (src[6] + src[7]) - (src[5] + src[8]) + 8) >> 4];
        dst[7] = cm[(9 * (src[7] + src[8]) - (src[6] + src[9]) + 8) >> 4];

        uint8_t* dst1 = dst + dstStride;
        uint8_t* src1 = src + srcStride;

        // Second row
        dst1[0] = cm[(9 * (src1[0] + src1[1]) - (src1[-1] + src1[2]) + 8) >> 4];
        dst1[1] = cm[(9 * (src1[1] + src1[2]) - (src1[0] + src1[3]) + 8) >> 4];
        dst1[2] = cm[(9 * (src1[2] + src1[3]) - (src1[1] + src1[4]) + 8) >> 4];
        dst1[3] = cm[(9 * (src1[3] + src1[4]) - (src1[2] + src1[5]) + 8) >> 4];
        dst1[4] = cm[(9 * (src1[4] + src1[5]) - (src1[3] + src1[6]) + 8) >> 4];
        dst1[5] = cm[(9 * (src1[5] + src1[6]) - (src1[4] + src1[7]) + 8) >> 4];
        dst1[6] = cm[(9 * (src1[6] + src1[7]) - (src1[5] + src1[8]) + 8) >> 4];
        dst1[7] = cm[(9 * (src1[7] + src1[8]) - (src1[6] + src1[9]) + 8) >> 4];

        dst += 2 * dstStride;
        src += 2 * srcStride;
    } else {
        // Handle odd h: process last row
        dst[0] = cm[(9 * (src[0] + src[1]) - (src[-1] + src[2]) + 8) >> 4];
        dst[1] = cm[(9 * (src[1] + src[2]) - (src[0] + src[3]) + 8) >> 4];
        dst[2] = cm[(9 * (src[2] + src[3]) - (src[1] + src[4]) + 8) >> 4];
        dst[3] = cm[(9 * (src[3] + src[4]) - (src[2] + src[5]) + 8) >> 4];
        dst[4] = cm[(9 * (src[4] + src[5]) - (src[3] + src[6]) + 8) >> 4];
        dst[5] = cm[(9 * (src[5] + src[6]) - (src[4] + src[7]) + 8) >> 4];
        dst[6] = cm[(9 * (src[6] + src[7]) - (src[5] + src[8]) + 8) >> 4];
        dst[7] = cm[(9 * (src[7] + src[8]) - (src[6] + src[9]) + 8) >> 4];

        dst += dstStride;
        src += srcStride;
    }
}
}
