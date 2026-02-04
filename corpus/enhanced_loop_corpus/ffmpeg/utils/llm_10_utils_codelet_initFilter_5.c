#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **filterPos;
extern int xInc;
extern int dstW;
extern int filterSize;
extern int64_t *filter;
extern  int64_t fone;
extern int i;
extern int64_t xDstInSrc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int unroll_factor = 4;
    int limit = dstW - (dstW % unroll_factor);
    for (i = 0; i < limit; i += unroll_factor) {
        int xx0 = (xDstInSrc - ((filterSize - 1) << 15) + (1 << 15)) >> 16;
        (*filterPos)[i] = xx0;
        filter[i] = fone;
        xDstInSrc += xInc;

        int xx1 = (xDstInSrc - ((filterSize - 1) << 15) + (1 << 15)) >> 16;
        (*filterPos)[i+1] = xx1;
        filter[i+1] = fone;
        xDstInSrc += xInc;

        int xx2 = (xDstInSrc - ((filterSize - 1) << 15) + (1 << 15)) >> 16;
        (*filterPos)[i+2] = xx2;
        filter[i+2] = fone;
        xDstInSrc += xInc;

        int xx3 = (xDstInSrc - ((filterSize - 1) << 15) + (1 << 15)) >> 16;
        (*filterPos)[i+3] = xx3;
        filter[i+3] = fone;
        xDstInSrc += xInc;
    }
    for (; i < dstW; i++) {
        int xx = (xDstInSrc - ((filterSize - 1) << 15) + (1 << 15)) >> 16;
        (*filterPos)[i] = xx;
        filter[i] = fone;
        xDstInSrc += xInc;
    }
}
