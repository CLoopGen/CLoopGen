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
    int base_idx_filter2 = i * filter2Size;
    int base_idx_filter = i * filterSize;
    if (srcFilter) {
        for (k = 0; k < srcFilter->length; k++) {
            double *srcCoeffPtr = &srcFilter->coeff[k];
            int64_t *filterSrcPtr = &filter[base_idx_filter];
            int64_t *filter2DstPtr = &filter2[base_idx_filter2 + k];
            for (j = 0; j < filterSize; j++) {
                filter2DstPtr[j] += (*srcCoeffPtr) * filterSrcPtr[j];
            }
        }
    } else {
        int64_t *src = &filter[base_idx_filter];
        int64_t *dst = &filter2[base_idx_filter2];
        for (j = 0; j < filterSize; j++) {
            dst[j] = src[j];
        }
    }
    (*filterPos)[i] += (filterSize - 1) / 2 - (filter2Size - 1) / 2;
}
}
