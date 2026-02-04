#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint16_t *dst;
uint16_t *src;
int A;
int B;
int C;
int D;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * (1 << 20)) / sizeof(uint16_t))

static uint16_t buffer[2][TOTAL_ELEMENTS];

void init_vars() {
    // Initialize coefficients
    A = 15;
    B = 7;
    C = 9;
    D = 5;

    // Set image-like dimensions
    int width = 1024;
    stride = width;
    h = TOTAL_ELEMENTS / (2 * stride);  // Use half the buffer for src, half for dst
    if (h > 10000) h = 10000;  // Cap height to avoid overflow

    // Ensure we don't exceed buffer bounds
    while (h * stride + 4 > TOTAL_ELEMENTS / 2) {
        h--;
    }

    // Assign buffers
    dst = buffer[0];
    src = buffer[1];

    // Initialize src data to prevent undefined behavior
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < stride; x++) {
            src[y * stride + x] = (uint16_t)(x * y % 257);
        }
    }

    // Initialize dst data
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < stride; x++) {
            dst[y * stride + x] = (uint16_t)(x + y);
        }
    }

    // Initialize loop index
    i = 0;
}