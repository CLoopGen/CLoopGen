#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
ptrdiff_t stride;
int i;
unsigned int dc0;

static uint8_t *allocated_buffer;

void init_vars() {
    size_t total_size = 16 * 1024 * 1024; // 16 MB for sufficient runtime (~0.01 sec on modern CPU)
    stride = 32; // Ensure stride is reasonable for alignment and access
    dc0 = 0xDEADBEEFu;

    // Allocate buffer to ensure all memory accesses in loop are valid
    // Loop uses i from 4 to 7: indices 4,5,6,7 -> max offset = 7 * stride + 2 * sizeof(uint32_t)
    size_t required_offset = (7 * stride) + (2 * sizeof(uint32_t));
    if (total_size < required_offset) {
        total_size = required_offset * 2; // Ensure buffer is large enough
    }

    allocated_buffer = aligned_alloc(32, total_size);
    if (!allocated_buffer) {
        exit(1);
    }

    src = allocated_buffer;
}

__attribute__((destructor)) void cleanup() {
    free(allocated_buffer);
}