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

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    // Initialize coefficients
    A = 15;
    B = 27;
    C = 33;
    D = 45;
    bias = 32;

    // Define image dimensions
    int width = 8;
    h = 32768;  // Total elements processed: ~256KB of output data

    // Stride is in bytes, assuming row-major layout with some padding to prevent false sharing
    stride = width + 8;

    // Allocate buffers with sufficient size to avoid out-of-bounds access
    // Each row uses 'width' elements, but we access up to src[stride + 8], so need extra padding per row
    size_t row_size = (stride + 9) * sizeof(uint8_t);
    size_t total_size = h * row_size;

    src_buffer = (uint8_t*)aligned_alloc(32, total_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, total_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source and destination buffers
    for (size_t idx = 0; idx < total_size; ++idx) {
        src_buffer[idx] = rand() % 256;
        dst_buffer[idx] = rand() % 256;
    }

    // Set pointers
    src = src_buffer;
    dst = dst_buffer;
}