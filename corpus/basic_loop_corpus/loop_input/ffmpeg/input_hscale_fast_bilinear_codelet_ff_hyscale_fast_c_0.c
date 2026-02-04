#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int16_t *dst;
int dstWidth;
uint8_t *src;
int xInc;
int i;
unsigned int xpos;

#define SRC_SIZE (256 << 20) // 256 MB for src
#define DST_SIZE (4 << 20)   // ~4 MB, ensures loop runs ~0.01s with reasonable i count

void init_vars() {
    // Allocate memory
    dst = aligned_alloc(32, DST_SIZE * sizeof(int16_t));
    src = aligned_alloc(32, SRC_SIZE * sizeof(uint8_t));

    // Initialize arrays to avoid undefined behavior
    for (size_t j = 0; j < DST_SIZE; j++) {
        dst[j] = 0;
    }
    for (size_t j = 0; j < SRC_SIZE; j++) {
        src[j] = (uint8_t)(j & 0xFF);
    }

    // Set parameters
    dstWidth = DST_SIZE;  // number of iterations
    xInc = 18000;         // fixed-point increment: controls stepping through src
    xpos = 0;             // initial position in fixed-point (16.16)

    // Ensure that xx+1 never exceeds SRC_SIZE-1
    // max xx = (xpos + (dstWidth - 1) * xInc) >> 16
    // We must have: ((xpos + (dstWidth - 1) * xInc) >> 16) + 1 < SRC_SIZE
    // Adjust dstWidth if necessary to prevent out-of-bounds access
    unsigned int max_xx = (xpos + (unsigned long)(dstWidth - 1) * (unsigned long)xInc) >> 16;
    while (max_xx + 1 >= SRC_SIZE && dstWidth > 0) {
        dstWidth--;
        max_xx = (xpos + (unsigned long)(dstWidth - 1) * (unsigned long)xInc) >> 16;
    }
}