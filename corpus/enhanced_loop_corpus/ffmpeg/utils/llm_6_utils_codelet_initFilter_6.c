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
    int xx = (xDstInSrc - ((filterSize - 1) << 15) + (1 << 15)) >> 16;
    int j;
    (*filterPos)[i] = xx;
    int64_t baseX = xDstInSrc;
    for (j = 0; j < filterSize; j++) {
        int64_t diff = ((int64_t)xx * (1 << 16)) - baseX;
        int64_t absDiff = diff >= 0 ? diff : -diff;
        int64_t coeff = fone - absDiff * (fone >> 16);
        if (coeff < 0)
            coeff = 0;
        filter[i * filterSize + j] = coeff;
        xx++;
    }
    xDstInSrc += xInc;
}
}
