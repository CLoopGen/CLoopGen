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
    const size_t dataSize = 128 * 1024 * 1024; // ~128MB total data
    dstWidth = dataSize / sizeof(int16_t);
    srcW = dataSize / 2;
    xInc = 65536; // ensures (i * xInc) >> 16 decreases by 1 per step

    src = (uint8_t *)calloc(srcW, sizeof(uint8_t));
    dst = (int16_t *)malloc(dstWidth * sizeof(int16_t));

    if (!src || !dst) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < srcW; j++) {
        src[j] = (uint8_t)(j % 256);
    }

    for (int j = 0; j < dstWidth; j++) {
        dst[j] = 0;
    }
}