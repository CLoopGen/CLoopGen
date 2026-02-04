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
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024 / sizeof(uint16_t))

static uint16_t buffer[2][TOTAL_ELEMENTS];

void init_vars() {
    // Initialize coefficients
    A = 15;
    B = 8;
    C = 6;
    D = 13;

    // Set image height and stride
    h = 512;
    stride = 1024;

    // Ensure dimensions fit within allocated buffer
    // Each row uses up to (stride + 8) elements, so we need at least h * stride total
    if (h * stride > TOTAL_ELEMENTS / 2) {
        h = (TOTAL_ELEMENTS / 2) / stride;
    }

    // Initialize pointers to aligned internal buffers
    dst = buffer[0];
    src = buffer[1];

    // Initialize src with non-zero test data to avoid trivial optimization
    for (int idx = 0; idx < TOTAL_ELEMENTS; idx++) {
        src[idx] = (uint16_t)(idx % 257);
    }

    // Zero-initialize dst
    for (int idx = 0; idx < TOTAL_ELEMENTS; idx++) {
        dst[idx] = 0;
    }
}