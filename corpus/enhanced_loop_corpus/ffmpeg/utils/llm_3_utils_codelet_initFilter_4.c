#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **filterPos;
extern int dstW;
extern int filterSize;
extern int64_t *filter;
extern  int64_t fone;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every second element in forward pass, then fill remaining
    int stride = 2;
    // First pass: strided access
    for (i = 0; i < dstW; i += stride) {
        filter[i * filterSize] = fone;
        (*filterPos)[i] = i;
    }
    // Second pass: fill the skipped elements
    for (i = 1; i < dstW; i += stride) {
        filter[i * filterSize] = fone;
        (*filterPos)[i] = i;
    }
}
