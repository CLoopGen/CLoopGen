#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
int dstWidth;
uint8_t *src;
int srcW;
int xInc;
int i;

void init_vars() {
    srcW = 1024;
    dstWidth = 512 * 1024; // ~512k elements to ensure loop runs long enough
    xInc = 131072; // 2^17, chosen so that (i * xInc) >> 16 scales appropriately

    src = (uint8_t *)aligned_alloc(32, srcW * sizeof(uint8_t));
    dst = (int16_t *)aligned_alloc(32, dstWidth * sizeof(int16_t));

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < srcW; j++) {
        src[j] = (uint8_t)(j & 0xFF);
    }
    for (int j = 0; j < dstWidth; j++) {
        dst[j] = 0;
    }
}