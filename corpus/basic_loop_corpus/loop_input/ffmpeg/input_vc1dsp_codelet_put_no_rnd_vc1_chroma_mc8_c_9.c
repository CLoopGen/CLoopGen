#include <stdlib.h>
#include <stdint.h>
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

#define DATA_SIZE (128 << 20) // 128 MB total data size

static uint8_t *internal_src_buffer;
static uint8_t *internal_dst_buffer;

void init_vars() {
    // Initialize constants
    A = 16;
    B = 32;
    C = 48;
    D = 64;
    h = 1024;
    stride = 256;
    i = 0;

    // Allocate buffers with padding to prevent out-of-bounds access
    // Each row accesses up to [x+1] and [stride + x+1], so we need at least +2 extra in width
    // And we access up to h + 1 rows due to [stride + ...], so need +1 extra row
    size_t row_size = stride + 2;
    size_t total_elements = (h + 1) * row_size;

    internal_src_buffer = (uint8_t*)aligned_alloc(32, total_elements * sizeof(uint8_t));
    internal_dst_buffer = (uint8_t*)aligned_alloc(32, total_elements * sizeof(uint8_t));

    if (!internal_src_buffer || !internal_dst_buffer) {
        exit(1);
    }

    // Initialize source data with non-zero values for meaningful computation
    for (size_t idx = 0; idx < total_elements; idx++) {
        internal_src_buffer[idx] = (uint8_t)(idx % 251);
        internal_dst_buffer[idx] = 0;
    }

    // Set the external pointers to point within the allocated buffers
    // Skip first row and first column to allow safe indexing from base pointer
    src = internal_src_buffer + row_size + 1; // Point to (1,1) in 2D layout
    dst = internal_dst_buffer + row_size + 1; // Same offset for dst
}