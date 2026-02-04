#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst1;
int16_t *dst2;
int dstWidth;
uint8_t *src1;
uint8_t *src2;
int srcW;
int xInc;
int i;

void init_vars() {
    const size_t total_data_size = 100 * 1024 * 1024; // ~100 MB of total data
    srcW = 800;
    dstWidth = total_data_size / (sizeof(int16_t) * 2 + sizeof(uint8_t) * 2) * 2;
    if (dstWidth < srcW) dstWidth = srcW * 2; // Ensure dstWidth >= srcW for meaningful loop

    xInc = (srcW << 16) / dstWidth; // ensures some iterations occur

    // Allocate arrays
    dst1 = aligned_alloc(32, dstWidth * sizeof(int16_t));
    dst2 = aligned_alloc(32, dstWidth * sizeof(int16_t));
    src1 = malloc(srcW * sizeof(uint8_t));
    src2 = malloc(srcW * sizeof(uint8_t));

    // Initialize src arrays to avoid undefined behavior
    for (int j = 0; j < srcW; j++) {
        src1[j] = (uint8_t)(j % 256);
        src2[j] = (uint8_t)((2 * j) % 256);
    }

    // Initialize dst arrays to known values
    for (int j = 0; j < dstWidth; j++) {
        dst1[j] = 0;
        dst2[j] = 0;
    }
}