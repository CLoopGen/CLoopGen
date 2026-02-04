#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

extern int32_t **filterPos;
extern int dstW;
extern SwsVector *srcFilter;
extern int i;
extern int filterSize;
extern int filter2Size;
extern int64_t *filter;
extern int64_t *filter2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i, j, k;
for (i = 0; i < dstW; i++) {
    (*filterPos)[i] += (filterSize - 1) / 2 - (filter2Size - 1) / 2;
}

if (srcFilter) {
    for (i = 0; i < dstW; i++) {
        for (j = 0; j < filterSize; j++) {
            int64_t temp = filter[i * filterSize + j];
            for (k = 0; k < srcFilter->length; k++) {
                filter2[i * filter2Size + k + j] += srcFilter->coeff[k] * temp;
            }
        }
    }
} else {
    for (i = 0; i < dstW; i++) {
        int idx_dst = i * filter2Size;
        int idx_src = i * filterSize;
        for (j = 0; j < filterSize; j++) {
            filter2[idx_dst + j] = filter[idx_src + j];
        }
    }
}
}
