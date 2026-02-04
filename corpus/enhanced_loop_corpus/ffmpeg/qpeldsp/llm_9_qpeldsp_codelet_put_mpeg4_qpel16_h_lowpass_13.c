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
    const int offset1 = 0, offset2 = srcStride;
    // Unroll two iterations to increase computational intensity
    // First "iteration" at current row
    dst[offset1 +  0] = cm[(((src[offset1 +  0] + src[offset1 +  1]) * 20 - (src[offset1 +  0] + src[offset1 +  2]) * 6 + 
                             (src[offset1 +  0] + src[offset1 +  3]) * 3 - (src[offset1 +  2] + src[offset1 +  4])) + 16) >> 5];
    dst[offset1 +  8] = cm[(((src[offset1 +  8] + src[offset1 +  9]) * 20 - (src[offset1 +  7] + src[offset1 + 10]) * 6 + 
                             (src[offset1 +  6] + src[offset1 + 11]) * 3 - (src[offset1 +  5] + src[offset1 + 12])) + 16) >> 5];
    dst[offset1 +  4] = cm[(((src[offset1 +  4] + src[offset1 +  5]) * 20 - (src[offset1 +  3] + src[offset1 +  6]) * 6 + 
                             (src[offset1 +  2] + src[offset1 +  7]) * 3 - (src[offset1 +  1] + src[offset1 +  8])) + 16) >> 5];
    dst[offset1 + 12] = cm[(((src[offset1 + 12] + src[offset1 + 13]) * 20 - (src[offset1 + 11] + src[offset1 + 14]) * 6 + 
                             (src[offset1 + 10] + src[offset1 + 15]) * 3 - (src[offset1 +  9] + src[offset1 + 16])) + 16) >> 5];

    // Second "iteration" at next row (if exists)
    if (i + 1 < h) {
        dst[offset2 +  0] = cm[(((src[offset2 +  0] + src[offset2 +  1]) * 20 - (src[offset2 +  0] + src[offset2 +  2]) * 6 + 
                                 (src[offset2 +  0] + src[offset2 +  3]) * 3 - (src[offset2 +  2] + src[offset2 +  4])) + 16) >> 5];
        dst[offset2 +  8] = cm[(((src[offset2 +  8] + src[offset2 +  9]) * 20 - (src[offset2 +  7] + src[offset2 + 10]) * 6 + 
                                 (src[offset2 +  6] + src[offset2 + 11]) * 3 - (src[offset2 +  5] + src[offset2 + 12])) + 16) >> 5];
        dst[offset2 +  4] = cm[(((src[offset2 +  4] + src[offset2 +  5]) * 20 - (src[offset2 +  3] + src[offset2 +  6]) * 6 + 
                                 (src[offset2 +  2] + src[offset2 +  7]) * 3 - (src[offset2 +  1] + src[offset2 +  8])) + 16) >> 5];
        dst[offset2 + 12] = cm[(((src[offset2 + 12] + src[offset2 + 13]) * 20 - (src[offset2 + 11] + src[offset2 + 14]) * 6 + 
                                 (src[offset2 + 10] + src[offset2 + 15]) * 3 - (src[offset2 +  9] + src[offset2 + 16])) + 16) >> 5];
    }

    // Advance pointers by two rows
    dst += 2 * dstStride;
    src += 2 * srcStride;
}
}
