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
    for (i = 0; i < dstW; i += 2) {
        int xx1 = (xDstInSrc - ((filterSize - 1) << 15) + (1 << 15)) >> 16;
        (*filterPos)[i] = xx1;
        filter[i] = fone;
        xDstInSrc += xInc;

        if (i + 1 < dstW) {
            int xx2 = (xDstInSrc - ((filterSize - 1) << 15) + (1 << 15)) >> 16;
            (*filterPos)[i + 1] = xx2;
            filter[i + 1] = fone;
            xDstInSrc += xInc;
        }
    }
}
