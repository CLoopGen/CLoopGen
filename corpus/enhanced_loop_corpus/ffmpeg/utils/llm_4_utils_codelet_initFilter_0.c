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
    if (!srcFilter) {
        for (j = 0; j < filterSize; j++)
            filter2[i * filter2Size + j] = filter[i * filterSize + j];
    } else {
        for (k = 0; k < srcFilter->length; k++) {
            for (j = 0; j < filterSize; j++)
                filter2[i * filter2Size + k + j] += srcFilter->coeff[k] * filter[i * filterSize + j];
        }
    }
    (*filterPos)[i] += (filterSize - 1) / 2 - (filter2Size - 1) / 2;
}
}
