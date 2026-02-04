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
int step = 2;
for (i = 0; i < dstW; i += step) {
    int xx1 = (xDstInSrc - ((filterSize - 1) << 15) + (1 << 15)) >> 16;
    int xx2 = (xDstInSrc + xInc - ((filterSize - 1) << 15) + (1 << 15)) >> 16;
    int j;
    (*filterPos)[i] = xx1;
    if (i + 1 < dstW) (*filterPos)[i + 1] = xx2;

    for (j = 0; j < filterSize; j++) {
        int64_t coeff1 = fone - (((int64_t)xx1 * (1 << 16) - xDstInSrc) >= 0 ? ((int64_t)xx1 * (1 << 16) - xDstInSrc) : (-((int64_t)xx1 * (1 << 16) - xDstInSrc))) * (fone >> 16);
        if (coeff1 < 0) coeff1 = 0;
        filter[i * filterSize + j] = coeff1;
        xx1++;

        if (i + 1 < dstW) {
            int64_t coeff2 = fone - (((int64_t)xx2 * (1 << 16) - (xDstInSrc + xInc)) >= 0 ? ((int64_t)xx2 * (1 << 16) - (xDstInSrc + xInc)) : (-((int64_t)xx2 * (1 << 16) - (xDstInSrc + xInc)))) * (fone >> 16);
            if (coeff2 < 0) coeff2 = 0;
            filter[(i + 1) * filterSize + j] = coeff2;
            xx2++;
        }
    }
    xDstInSrc += xInc * step;
}
}
