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
for (i = 0; i < dstW; i++) {
    int j, k;
    if (srcFilter) {
        for (k = 0; k < srcFilter->length; k++) {
            int idx_base = i * filter2Size + k;
            for (j = 0; j < filterSize; j++) {
                filter2[idx_base + j] += srcFilter->coeff[k] * filter[i * filterSize + j];
            }
        }
    } else {
        int idx_dst = i * filter2Size;
        int idx_src = i * filterSize;
        for (j = 0; j < filterSize; j++) {
            filter2[idx_dst + j] = filter[idx_src + j];
        }
    }
    (*filterPos)[i] += (filterSize - 1) / 2 - (filter2Size - 1) / 2;
}
}
