#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int h;
int A;
int B;
int C;
int D;
int i;
int bias;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB for sufficient runtime (~0.01 sec on modern CPU)
static uint8_t internal_src[DATA_SIZE];
static uint8_t internal_dst[DATA_SIZE];

void init_vars() {
    // Initialize constants
    A = 15;
    B = 10;
    C = 8;
    D = 12;
    bias = 32; // Bias to center the rounding

    // Set height and stride to ensure no out-of-bounds access
    // Each row uses up to src[stride + 8], so we need at least 9 elements per row
    // Choose stride >= 9, and allocate rows accordingly.
    stride = 16; // Power of two, good for alignment and padding
    h = (DATA_SIZE / stride) / 2; // Use half the buffer for rows, conservative estimate

    // Ensure we don't exceed buffer bounds
    if (h * stride + stride + 8 >= DATA_SIZE) {
        h = (DATA_SIZE - stride - 8) / stride;
    }

    // Initialize pointers to internal buffers
    src = internal_src;
    dst = internal_dst;

    // Initialize src data to prevent undefined behavior
    for (int idx = 0; idx < DATA_SIZE; ++idx) {
        internal_src[idx] = (uint8_t)(idx % 251); // Prime mod for variation
    }
}