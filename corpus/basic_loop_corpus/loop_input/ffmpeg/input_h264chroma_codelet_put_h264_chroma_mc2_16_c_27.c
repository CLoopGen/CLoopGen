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

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of data to target ~0.01s runtime
static uint16_t *buffer_dst;
static uint16_t *buffer_src;

void init_vars() {
    // Initialize coefficients
    A = 15;
    B = 25;
    C = 35;
    D = 45;

    // Set image height and stride
    h = 8192; // Adjust to fit data size
    stride = 8192;

    // Ensure we don't exceed bounds: we access src[0], src[1], src[stride+0], src[stride+1], src[stride+2]
    // So we need at least (h + 1) rows and (3) columns in src, and h rows in dst
    if (stride < 3 || h < 1) {
        fprintf(stderr, "Invalid dimensions\n");
        exit(1);
    }

    // Allocate buffers with padding for safe access
    buffer_src = aligned_alloc(64, sizeof(uint16_t) * (h + 1) * stride + 2);
    buffer_dst = aligned_alloc(64, sizeof(uint16_t) * h * stride);

    if (!buffer_src || !buffer_dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = buffer_src;
    dst = buffer_dst;

    // Initialize input data
    for (int idx = 0; idx < (h + 1) * stride + 2; idx++) {
        buffer_src[idx] = rand() & 0xFFFF;
    }

    // Initialize output data to zero
    for (int idx = 0; idx < h * stride; idx++) {
        buffer_dst[idx] = 0;
    }
}