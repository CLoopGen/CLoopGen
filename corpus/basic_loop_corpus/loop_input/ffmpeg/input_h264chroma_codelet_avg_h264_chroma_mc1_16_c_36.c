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
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(uint16_t))

static uint16_t buffer_src[TOTAL_ELEMENTS];
static uint16_t buffer_dst[TOTAL_ELEMENTS];

void init_vars() {
    // Initialize coefficients
    A = 17;
    B = 37;
    C = 19;
    D = 41;

    // Set image height and stride
    stride = 8192; // Large stride to simulate row-major image with padding
    h = TOTAL_ELEMENTS / stride; // Adjust h so we don't overflow

    if (h <= 0) {
        h = 1;
    }
    if (h * stride > TOTAL_ELEMENTS) {
        h = TOTAL_ELEMENTS / stride;
    }

    // Ensure src and dst point into the buffers with valid access to [stride+1]
    src = buffer_src;
    dst = buffer_dst;

    // Initialize source data to avoid undefined behavior
    for (int idx = 0; idx < TOTAL_ELEMENTS; ++idx) {
        buffer_src[idx] = (uint16_t)(idx % 257);
    }
    for (int idx = 0; idx < TOTAL_ELEMENTS; ++idx) {
        buffer_dst[idx] = (uint16_t)((idx + 123) % 257);
    }
}