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
    int *indirect_pos = (int*)alloca(filterSize * sizeof(int));
    for (j = 0; j < filterSize; j++) {
        indirect_pos[j] = j; // Simulate indirect access pattern
    }
    if (srcFilter) {
        for (k = 0; k < srcFilter->length; k++) {
            for (j = 0; j < filterSize; j++) {
                int idx = indirect_pos[j]; // Indirect indexing
                filter2[i * filter2Size + k + idx] += srcFilter->coeff[k] * filter[i * filterSize + idx];
            }
        }
    } else {
        for (j = 0; j < filterSize; j++) {
            int idx = indirect_pos[j]; // Indirect indexing
            filter2[i * filter2Size + idx] = filter[i * filterSize + idx];
        }
    }
    (*filterPos)[i] += (filterSize - 1) / 2 - (filter2Size - 1) / 2;
}
}
