#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    const int offset = i * 8;
    const int idx[] = {
        -2*8, -1*8, 0*8, 1*8, 2*8, 3*8, 4*8, 5*8, 6*8, 7*8, 8*8, 9*8, 10*8
    };

    const int tmpVals[13] = {
        tmp[idx[0]], tmp[idx[1]], tmp[idx[2]], tmp[idx[3]], tmp[idx[4]],
        tmp[idx[5]], tmp[idx[6]], tmp[idx[7]], tmp[idx[8]], tmp[idx[9]],
        tmp[idx[10]], tmp[idx[11]], tmp[idx[12]]
    };

    dst[0 * dstStride] = cm[((0 * tmpVals[0] + -1 * tmpVals[1] + 5 * tmpVals[2] + 5 * tmpVals[3] + -1 * tmpVals[4] + 0 * tmpVals[5]) + 512) >> 10];
    dst[1 * dstStride] = cm[((0 * tmpVals[1] + -1 * tmpVals[2] + 5 * tmpVals[3] + 5 * tmpVals[4] + -1 * tmpVals[5] + 0 * tmpVals[6]) + 512) >> 10];
    dst[2 * dstStride] = cm[((0 * tmpVals[2] + -1 * tmpVals[3] + 5 * tmpVals[4] + 5 * tmpVals[5] + -1 * tmpVals[6] + 0 * tmpVals[7]) + 512) >> 10];
    dst[3 * dstStride] = cm[((0 * tmpVals[3] + -1 * tmpVals[4] + 5 * tmpVals[5] + 5 * tmpVals[6] + -1 * tmpVals[7] + 0 * tmpVals[8]) + 512) >> 10];
    dst[4 * dstStride] = cm[((0 * tmpVals[4] + -1 * tmpVals[5] + 5 * tmpVals[6] + 5 * tmpVals[7] + -1 * tmpVals[8] + 0 * tmpVals[9]) + 512) >> 10];
    dst[5 * dstStride] = cm[((0 * tmpVals[5] + -1 * tmpVals[6] + 5 * tmpVals[7] + 5 * tmpVals[8] + -1 * tmpVals[9] + 0 * tmpVals[10]) + 512) >> 10];
    dst[6 * dstStride] = cm[((0 * tmpVals[6] + -1 * tmpVals[7] + 5 * tmpVals[8] + 5 * tmpVals[9] + -1 * tmpVals[10] + 0 * tmpVals[11]) + 512) >> 10];
    dst[7 * dstStride] = cm[((0 * tmpVals[7] + -1 * tmpVals[8] + 5 * tmpVals[9] + 5 * tmpVals[10] + -1 * tmpVals[11] + 0 * tmpVals[12]) + 512) >> 10];

    dst++;
    tmp++;
}
}
