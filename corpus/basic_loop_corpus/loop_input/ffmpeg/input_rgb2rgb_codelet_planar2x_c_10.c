#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int srcWidth;
int srcHeight;
int srcStride;
int dstStride;
int x;
int y;

void init_vars() {
    srcWidth = 1024;
    srcHeight = 768;
    srcStride = 1024;
    dstStride = 2048;

    size_t srcSize = (size_t)srcStride * (size_t)srcHeight;
    size_t dstSize = (size_t)dstStride * (size_t)(srcHeight * 2);

    src = (uint8_t*)aligned_alloc(32, srcSize);
    dst = (uint8_t*)aligned_alloc(32, dstSize);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < srcSize; i++) {
        src[i] = rand() & 0xFF;
    }

    for (size_t i = 0; i < dstSize; i++) {
        dst[i] = 0;
    }

    x = 0;
    y = 0;
}