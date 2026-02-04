#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc0;
int dc1;
int dc2;
uint16_t *src;

static uint16_t *src_buffer;

void init_vars() {
    // Set up problem size to achieve desired runtime
    // Use a buffer large enough to avoid out-of-bounds access with given loop logic
    const int buffer_width = 16;
    const int buffer_height = 16;
    stride = buffer_width;
    
    // Allocate sufficient memory to cover all indexed locations in the loop
    // Maximum index accessed: src[-1 + (i+4)*stride] where i=3 -> -1 + 7*stride
    // Minimum index: src[-1 + i*stride] where i=0 -> -1, so we need padding at start
    // Also access src[i - stride] and src[4 + i - stride] -> negative offsets possible
    // To make all accesses valid, allocate with generous margins
    const ptrdiff_t total_size = 8 * stride + 16;  // more than enough for safe indexing
    src_buffer = aligned_alloc(64, total_size * sizeof(uint16_t));
    if (!src_buffer) {
        exit(1);
    }

    // Initialize buffer content
    for (size_t idx = 0; idx < total_size; idx++) {
        src_buffer[idx] = (uint16_t)(idx & 0xFF);
    }

    // Set src pointer to middle of buffer to allow negative indexing
    // We need to ensure:
    //   - src[-1] is valid => src must be >= buffer+1
    //   - src[-stride] is valid => src must be >= buffer+stride
    // Choose src = src_buffer + 8*stride to have plenty of room below
    src = src_buffer + 8 * stride;

    // Initialize accumulators
    dc0 = 0;
    dc1 = 0;
    dc2 = 0;
}