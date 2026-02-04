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
    int64_t baseCoeff = fone;
    for (j = 0; j < filterSize; j++) {
        int64_t pos = (int64_t)xx * (1 << 16);
        int64_t error = pos - xDstInSrc;
        int64_t absError = error;
        if (error < 0) absError = -error;
        int64_t stepReduction = absError >> 16;
        int64_t coeff = baseCoeff - (stepReduction * (fone >> 16));
        if (coeff >= 0 && stepReduction <= (fone >> 16)) {
            filter[i * filterSize + j] = coeff;
        } else {
            filter[i * filterSize + j] = 0;
        }
        xx++;
    }
    xDstInSrc += xInc;
}
}
