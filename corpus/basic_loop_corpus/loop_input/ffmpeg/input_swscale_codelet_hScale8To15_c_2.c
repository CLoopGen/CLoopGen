#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
int dstW;
uint8_t *src;
int16_t *filter;
int32_t *filterPos;
int filterSize;
int i;

void init_vars() {
    dstW = 65536;
    filterSize = 16;

    dst = (int16_t*)aligned_alloc(32, dstW * sizeof(int16_t));
    src = (uint8_t*)aligned_alloc(32, (dstW + filterSize) * sizeof(uint8_t));
    filter = (int16_t*)aligned_alloc(32, dstW * filterSize * sizeof(int16_t));
    filterPos = (int32_t*)aligned_alloc(32, dstW * sizeof(int32_t));

    for (int idx = 0; idx < dstW; idx++) {
        filterPos[idx] = idx % (dstW + filterSize - filterSize);
    }

    for (int idx = 0; idx < (dstW + filterSize); idx++) {
        src[idx] = (uint8_t)(idx % 256);
    }

    for (int idx = 0; idx < dstW * filterSize; idx++) {
        filter[idx] = (int16_t)((idx % 256) - 128);
    }

    for (int idx = 0; idx < dstW; idx++) {
        dst[idx] = 0;
    }
}