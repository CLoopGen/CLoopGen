#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

int32_t **filterPos;
int dstW;
SwsVector *srcFilter;
int i;
int filterSize;
int filter2Size;
int64_t *filter;
int64_t *filter2;

void init_vars() {
    dstW = 1000;
    filterSize = 8;
    filter2Size = 12;
    
    filterPos = (int32_t**)calloc(dstW, sizeof(int32_t*));
    for (int idx = 0; idx < dstW; idx++) {
        filterPos[idx] = (int32_t*)calloc(1, sizeof(int32_t));
    }
    
    srcFilter = (SwsVector*)malloc(sizeof(SwsVector));
    srcFilter->length = 4;
    srcFilter->coeff = (double*)malloc(srcFilter->length * sizeof(double));
    for (int k = 0; k < srcFilter->length; k++) {
        srcFilter->coeff[k] = 1.0 + k * 0.25;
    }
    
    size_t total_filter_size = (size_t)dstW * filterSize;
    size_t total_filter2_size = (size_t)dstW * filter2Size;
    
    filter = (int64_t*)calloc(total_filter_size, sizeof(int64_t));
    filter2 = (int64_t*)calloc(total_filter2_size, sizeof(int64_t));
    
    for (size_t idx = 0; idx < total_filter_size; idx++) {
        filter[idx] = (int64_t)(idx % 1000);
    }
}