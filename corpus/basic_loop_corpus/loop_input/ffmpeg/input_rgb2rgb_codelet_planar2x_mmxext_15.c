#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int x86_reg;

uint8_t *src;
uint8_t *dst;
int srcWidth;
int srcHeight;
int srcStride;
int dstStride;
int x;
int y;

#define DATA_SIZE_MB 64

static size_t total_data_size = DATA_SIZE_MB * 1024 * 1024;

void init_vars() {
    srcWidth = 1024;
    srcHeight = (total_data_size / srcWidth + 1) / 2; // Approximate to get ~64MB
    if (srcHeight < 2) srcHeight = 2;

    srcStride = srcWidth;
    dstStride = srcWidth * 2;

    size_t srcSize = srcStride * srcHeight;
    size_t dstSize = dstStride * srcHeight * 2;

    src = (uint8_t*)aligned_alloc(16, srcSize);
    dst = (uint8_t*)aligned_alloc(16, dstSize);

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