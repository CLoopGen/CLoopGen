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
int prev_xx = 0;
for (i = 0; i < dstW; i++) {
    int xx;
    if (i == 0) {
        xx = (xDstInSrc - ((filterSize - 1) << 15) + (1 << 15)) >> 16;
    } else {
        xx = prev_xx + (xInc >> 16);
    }
    int j;
    (*filterPos)[i] = xx;
    for (j = 0; j < filterSize; j++) {
        int64_t projected = (int64_t)xx * (1 << 16);
        int64_t error = projected - (xDstInSrc + j * (1LL << 16));
        int64_t absError = error >= 0 ? error : -error;
        int64_t coeff = fone - absError * (fone >> 16);
        if (coeff < 0)
            coeff = 0;
        filter[i * filterSize + j] = coeff;
    }
    prev_xx = xx;
    xDstInSrc += xInc;
}
}
