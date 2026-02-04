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
// Variant 1: Strided memory access (access every 2nd element, then fill in reverse order)
int stride = 2;
int j;
for (j = 0; j < dstW; j += stride) {
    int idx = j;
    int xx = (xDstInSrc - ((filterSize - 1) << 15) + (1 << 15)) >> 16;
    (*filterPos)[idx] = xx;
    filter[idx] = fone;
    xDstInSrc += xInc * stride;
}
// Fill the odd indices in a second forward pass with updated xDstInSrc
for (j = 1; j < dstW; j += stride) {
    int idx = j;
    int xx = (xDstInSrc - ((filterSize - 1) << 15) + (1 << 15)) >> 16;
    (*filterPos)[idx] = xx;
    filter[idx] = fone;
    xDstInSrc += xInc;
}
}
