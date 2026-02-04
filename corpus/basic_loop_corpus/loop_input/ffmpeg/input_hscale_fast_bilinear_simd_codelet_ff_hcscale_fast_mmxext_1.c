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
    // Set parameters to control loop behavior and ensure memory safety
    srcW = 1024;
    dstWidth = 512 * 1024; // ~0.5 million elements
    xInc = 64; // Fixed-point step: 64 << 16 represents a fractional increment

    // Allocate arrays with appropriate sizes
    dst1 = (int16_t*)aligned_alloc(32, dstWidth * sizeof(int16_t));
    dst2 = (int16_t*)aligned_alloc(32, dstWidth * sizeof(int16_t));
    src1 = (uint8_t*)aligned_alloc(32, srcW * sizeof(uint8_t));
    src2 = (uint8_t*)aligned_alloc(32, srcW * sizeof(uint8_t));

    // Initialize src arrays to avoid undefined behavior
    for (int j = 0; j < srcW; j++) {
        src1[j] = (uint8_t)(j & 0xFF);
        src2[j] = (uint8_t)((j * 7) & 0xFF);
    }

    // Ensure that initial condition (i * xInc) >> 16 >= srcW - 1 holds at start of loop
    // We need the loop to run for a significant number of iterations (~milliseconds)
    // With dstWidth=512k and xInc=64, the loop will terminate when (i * 64) >> 16 < 1023
    // i must be large enough so that early indices satisfy the condition

    // Initialize dst arrays to prevent use-after-init issues
    for (int j = 0; j < dstWidth; j++) {
        dst1[j] = 0;
        dst2[j] = 0;
    }
}