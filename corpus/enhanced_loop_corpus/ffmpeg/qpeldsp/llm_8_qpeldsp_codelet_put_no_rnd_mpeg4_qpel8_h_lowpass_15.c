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
    if (i + 1 < h) {
        // Process two rows per iteration to increase computational intensity
        // First row
        dst[0] = cm[(((src[0] + src[1]) * 20 - (src[0] + src[2]) * 6 + (src[1] + src[3]) * 3 - (src[2] + src[4])) + 15) >> 5];
        dst[1] = cm[(((src[1] + src[2]) * 20 - (src[0] + src[3]) * 6 + (src[0] + src[4]) * 3 - (src[1] + src[5])) + 15) >> 5];
        dst[2] = cm[(((src[2] + src[3]) * 20 - (src[1] + src[4]) * 6 + (src[0] + src[5]) * 3 - (src[0] + src[6])) + 15) >> 5];
        dst[3] = cm[(((src[3] + src[4]) * 20 - (src[2] + src[5]) * 6 + (src[1] + src[6]) * 3 - (src[0] + src[7])) + 15) >> 5];
        dst[4] = cm[(((src[4] + src[5]) * 20 - (src[3] + src[6]) * 6 + (src[2] + src[7]) * 3 - (src[1] + src[8])) + 15) >> 5];
        dst[5] = cm[(((src[5] + src[6]) * 20 - (src[4] + src[7]) * 6 + (src[3] + src[8]) * 3 - (src[2] + src[8])) + 15) >> 5];
        dst[6] = cm[(((src[6] + src[7]) * 20 - (src[5] + src[8]) * 6 + (src[4] + src[8]) * 3 - (src[3] + src[7])) + 15) >> 5];
        dst[7] = cm[(((src[7] + src[8]) * 20 - (src[6] + src[8]) * 6 + (src[5] + src[7]) * 3 - (src[4] + src[6])) + 15) >> 5];

        // Second row
        uint8_t *dst2 = dst + dstStride;
        uint8_t *src2 = src + srcStride;
        dst2[0] = cm[(((src2[0] + src2[1]) * 20 - (src2[0] + src2[2]) * 6 + (src2[1] + src2[3]) * 3 - (src2[2] + src2[4])) + 15) >> 5];
        dst2[1] = cm[(((src2[1] + src2[2]) * 20 - (src2[0] + src2[3]) * 6 + (src2[0] + src2[4]) * 3 - (src2[1] + src2[5])) + 15) >> 5];
        dst2[2] = cm[(((src2[2] + src2[3]) * 20 - (src2[1] + src2[4]) * 6 + (src2[0] + src2[5]) * 3 - (src2[0] + src2[6])) + 15) >> 5];
        dst2[3] = cm[(((src2[3] + src2[4]) * 20 - (src2[2] + src2[5]) * 6 + (src2[1] + src2[6]) * 3 - (src2[0] + src2[7])) + 15) >> 5];
        dst2[4] = cm[(((src2[4] + src2[5]) * 20 - (src2[3] + src2[6]) * 6 + (src2[2] + src2[7]) * 3 - (src2[1] + src2[8])) + 15) >> 5];
        dst2[5] = cm[(((src2[5] + src2[6]) * 20 - (src2[4] + src2[7]) * 6 + (src2[3] + src2[8]) * 3 - (src2[2] + src2[8])) + 15) >> 5];
        dst2[6] = cm[(((src2[6] + src2[7]) * 20 - (src2[5] + src2[8]) * 6 + (src2[4] + src2[8]) * 3 - (src2[3] + src2[7])) + 15) >> 5];
        dst2[7] = cm[(((src2[7] + src2[8]) * 20 - (src2[6] + src2[8]) * 6 + (src2[5] + src2[7]) * 3 - (src2[4] + src2[6])) + 15) >> 5];

        dst += 2 * dstStride;
        src += 2 * srcStride;
    } else {
        // Handle odd row count
        dst[0] = cm[(((src[0] + src[1]) * 20 - (src[0] + src[2]) * 6 + (src[1] + src[3]) * 3 - (src[2] + src[4])) + 15) >> 5];
        dst[1] = cm[(((src[1] + src[2]) * 20 - (src[0] + src[3]) * 6 + (src[0] + src[4]) * 3 - (src[1] + src[5])) + 15) >> 5];
        dst[2] = cm[(((src[2] + src[3]) * 20 - (src[1] + src[4]) * 6 + (src[0] + src[5]) * 3 - (src[0] + src[6])) + 15) >> 5];
        dst[3] = cm[(((src[3] + src[4]) * 20 - (src[2] + src[5]) * 6 + (src[1] + src[6]) * 3 - (src[0] + src[7])) + 15) >> 5];
        dst[4] = cm[(((src[4] + src[5]) * 20 - (src[3] + src[6]) * 6 + (src[2] + src[7]) * 3 - (src[1] + src[8])) + 15) >> 5];
        dst[5] = cm[(((src[5] + src[6]) * 20 - (src[4] + src[7]) * 6 + (src[3] + src[8]) * 3 - (src[2] + src[8])) + 15) >> 5];
        dst[6] = cm[(((src[6] + src[7]) * 20 - (src[5] + src[8]) * 6 + (src[4] + src[8]) * 3 - (src[3] + src[7])) + 15) >> 5];
        dst[7] = cm[(((src[7] + src[8]) * 20 - (src[6] + src[8]) * 6 + (src[5] + src[7]) * 3 - (src[4] + src[6])) + 15) >> 5];
        dst += dstStride;
        src += srcStride;
    }
}
}
