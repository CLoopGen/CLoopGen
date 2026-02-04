#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int dstW = 1 << 18;
uint8_t *src;
int16_t *filter;
int32_t *filterPos;
int filterSize = 8;
int i;
int32_t *dst;

void init_vars() {
    src = (uint8_t*)aligned_alloc(32, sizeof(uint8_t) * (dstW * filterSize + filterSize));
    filter = (int16_t*)aligned_alloc(32, sizeof(int16_t) * dstW * filterSize);
    filterPos = (int32_t*)aligned_alloc(32, sizeof(int32_t) * dstW);
    dst = (int32_t*)aligned_alloc(32, sizeof(int32_t) * dstW);

    for (int i = 0; i < dstW; i++) {
        filterPos[i] = i * filterSize;
    }

    for (int i = 0; i < dstW * filterSize; i++) {
        filter[i] = rand() % 17 - 8;
    }

    for (int i = 0; i < dstW * filterSize + filterSize; i++) {
        src[i] = rand() % 256;
    }
}