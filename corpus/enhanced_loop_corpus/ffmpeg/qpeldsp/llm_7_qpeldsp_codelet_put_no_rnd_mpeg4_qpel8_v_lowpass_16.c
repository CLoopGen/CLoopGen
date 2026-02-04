#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  uint8_t *cm;
extern  int w;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    const int src_offsets[] = {
        src[0 * srcStride], src[1 * srcStride], src[2 * srcStride],
        src[3 * srcStride], src[4 * srcStride], src[5 * srcStride],
        src[6 * srcStride], src[7 * srcStride], src[8 * srcStride]
    };

    uint8_t results[8];

    results[0] = cm[((((src_offsets[0] + src_offsets[1]) * 20 -
                       (src_offsets[0] + src_offsets[2]) * 6 +
                       (src_offsets[1] + src_offsets[3]) * 3 -
                       (src_offsets[2] + src_offsets[4])) + 15) >> 5)];

    results[1] = cm[((((src_offsets[1] + src_offsets[2]) * 20 -
                       (src_offsets[0] + src_offsets[3]) * 6 +
                       (src_offsets[0] + src_offsets[4]) * 3 -
                       (src_offsets[1] + src_offsets[5])) + 15) >> 5)];

    results[2] = cm[((((src_offsets[2] + src_offsets[3]) * 20 -
                       (src_offsets[1] + src_offsets[4]) * 6 +
                       (src_offsets[0] + src_offsets[5]) * 3 -
                       (src_offsets[0] + src_offsets[6])) + 15) >> 5)];

    results[3] = cm[((((src_offsets[3] + src_offsets[4]) * 20 -
                       (src_offsets[2] + src_offsets[5]) * 6 +
                       (src_offsets[1] + src_offsets[6]) * 3 -
                       (src_offsets[0] + src_offsets[7])) + 15) >> 5)];

    results[4] = cm[((((src_offsets[4] + src_offsets[5]) * 20 -
                       (src_offsets[3] + src_offsets[6]) * 6 +
                       (src_offsets[2] + src_offsets[7]) * 3 -
                       (src_offsets[1] + src_offsets[8])) + 15) >> 5)];

    results[5] = cm[((((src_offsets[5] + src_offsets[6]) * 20 -
                       (src_offsets[4] + src_offsets[7]) * 6 +
                       (src_offsets[3] + src_offsets[8]) * 3 -
                       (src_offsets[2] + src_offsets[8])) + 15) >> 5)];

    results[6] = cm[((((src_offsets[6] + src_offsets[7]) * 20 -
                       (src_offsets[5] + src_offsets[8]) * 6 +
                       (src_offsets[4] + src_offsets[8]) * 3 -
                       (src_offsets[3] + src_offsets[7])) + 15) >> 5)];

    results[7] = cm[((((src_offsets[7] + src_offsets[8]) * 20 -
                       (src_offsets[6] + src_offsets[8]) * 6 +
                       (src_offsets[5] + src_offsets[7]) * 3 -
                       (src_offsets[4] + src_offsets[6])) + 15) >> 5)];

    for (int j = 0; j < 8; j++) {
        dst[j * dstStride] = results[j];
    }

    dst++;
    src++;
}
}
