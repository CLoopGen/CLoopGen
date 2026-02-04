#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc0;
int dc1;
int dc2;
int dc3;
int dc4;
uint16_t *src;

static uint16_t *src_buffer;

void init_vars() {
    // Allocate sufficient data to achieve desired runtime
    // Use 16MB of data as compromise between small size and measurable execution time
    const size_t buffer_size = 1 << 24; // 16M elements, 32 MB total size
    src_buffer = (uint16_t*)aligned_alloc(64, buffer_size * sizeof(uint16_t));
    if (!src_buffer) {
        exit(1);
    }

    // Initialize buffer with predictable values to allow compiler to actually optimize
    for (size_t idx = 0; idx < buffer_size; idx++) {
        src_buffer[idx] = (uint16_t)(idx & 0xFFFF);
    }

    // Set stride to a reasonable value (e.g., 64 bytes -> 32 elements)
    stride = 32;

    // Ensure that all array accesses in the loop are within bounds
    // Maximum index accessed: -1 + (i + 12)*stride where i=3 -> -1 + 15*stride = -1 + 15*32 = 479
    // Also access: 4 + i - stride -> max when i=3: 7 - stride -> need base pointer offset so negative indices are valid
    // We need to ensure src[-1 + ...] and src[i - stride] etc. are valid

    // Shift the src pointer forward by enough to allow negative indexing
    // Maximum negative offset: -stride (when i=0) -> we need at least 'stride' padding at front
    ptrdiff_t padding = stride + 1;  // handle -1 and -stride safely
    src = src_buffer + padding;

    // Reset accumulators
    dc0 = 0;
    dc1 = 0;
    dc2 = 0;
    dc3 = 0;
    dc4 = 0;
}