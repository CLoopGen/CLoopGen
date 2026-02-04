#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int B;
int C;
int D;
int i;

#define DATA_SIZE (128 * 1024 * 1024)
static uint8_t buffer[DATA_SIZE];

void init_vars() {
    // Initialize coefficients
    A = 15;
    B = 7;
    C = 9;
    D = 5;

    // Set image height and stride
    h = 4096;
    stride = 8192; // Must be >= 9 to prevent out-of-bounds access

    // Ensure total memory usage fits within buffer
    size_t min_buffer_size = (h + 1) * stride * 2; // src and dst with stride, plus one row padding
    if (min_buffer_size > DATA_SIZE) {
        h = (DATA_SIZE / 2) / stride - 1;
    }

    // Assign buffers with proper alignment
    src = buffer;
    dst = buffer + (h + 1) * stride;

    // Initialize source data to avoid undefined behavior
    for (size_t idx = 0; idx < (h + 1) * stride + 9; ++idx) {
        src[idx] = (uint8_t)(idx % 251);
    }
}