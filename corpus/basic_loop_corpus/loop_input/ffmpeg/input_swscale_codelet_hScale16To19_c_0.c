#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int dstW = 16384;
int16_t *filter;
int32_t *filterPos;
int filterSize = 8;
int i;
int32_t *dst;
uint16_t *src;
int sh = 10;

void init_vars() {
    src = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * (dstW * filterSize + filterSize));
    dst = (int32_t*)aligned_alloc(32, sizeof(int32_t) * dstW);
    filter = (int16_t*)aligned_alloc(32, sizeof(int16_t) * dstW * filterSize);
    filterPos = (int32_t*)aligned_alloc(32, sizeof(int32_t) * dstW);

    for (int i = 0; i < dstW; i++) {
        filterPos[i] = i * filterSize;
        for (int j = 0; j < filterSize; j++) {
            filter[i * filterSize + j] = (int16_t)(j + 1);
        }
        dst[i] = 0;
    }

    for (int i = 0; i < dstW * filterSize + filterSize; i++) {
        src[i] = (uint16_t)(i % 256);
    }
}