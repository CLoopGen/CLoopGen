#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
int dstW;
int16_t *filter;
int32_t *filterPos;
int filterSize;
int i;
uint16_t *src;
int sh;

void init_vars() {
    dstW = 16384;
    filterSize = 16;
    sh = 8;

    src = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * (dstW + filterSize));
    dst = (int16_t*)aligned_alloc(32, sizeof(int16_t) * dstW);
    filter = (int16_t*)aligned_alloc(32, sizeof(int16_t) * dstW * filterSize);
    filterPos = (int32_t*)aligned_alloc(32, sizeof(int32_t) * dstW);

    for (i = 0; i < dstW; i++) {
        filterPos[i] = i;
        for (int j = 0; j < filterSize; j++) {
            filter[i * filterSize + j] = (int16_t)(j + 1);
        }
        src[i] = (uint16_t)(i % 256);
    }

    for (int j = 0; j < filterSize; j++) {
        src[dstW + j] = (uint16_t)((dstW + j) % 256);
    }
}