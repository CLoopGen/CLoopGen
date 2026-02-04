#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst1;
int16_t *dst2;
int dstWidth;
uint8_t *src1;
uint8_t *src2;
int xInc;
int i;
unsigned int xpos;

void init_vars() {
    const size_t src_size = 1 << 20; // 1MB for src arrays
    dstWidth = 1 << 19; // ~512K elements for dst arrays

    // Allocate memory
    src1 = (uint8_t*)aligned_alloc(32, src_size);
    src2 = (uint8_t*)aligned_alloc(32, src_size);
    dst1 = (int16_t*)aligned_alloc(32, dstWidth * sizeof(int16_t));
    dst2 = (int16_t*)aligned_alloc(32, dstWidth * sizeof(int16_t));

    // Initialize src data to avoid undefined behavior
    for (size_t j = 0; j < src_size; j++) {
        src1[j] = rand() & 0xFF;
        src2[j] = rand() & 0xFF;
    }

    // Set initial position and increment
    xpos = 1 << 16; // Start at fixed point value of 1.0
    xInc = (src_size - 2) << 16 / dstWidth; // Scale so we don't go out of bounds

    // Ensure that xx+1 is always valid: max xx should be <= src_size-2
    // With this xInc, maximum xpos will be roughly (dstWidth * xInc) + initial xpos
    // We set xInc conservatively above to stay safe
}