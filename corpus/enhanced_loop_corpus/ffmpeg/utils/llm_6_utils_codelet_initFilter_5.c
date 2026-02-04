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
for (i = 0; i < dstW; i++) {
    if (i % 2 == 0) {
        int xx = (xDstInSrc - ((filterSize - 1) << 15) + (1 << 15)) >> 16;
        (*filterPos)[i] = xx;
        filter[i] = fone;
    } else {
        (*filterPos)[i] = 0;
        filter[i] = 0;
    }
    xDstInSrc += xInc;
}
}
