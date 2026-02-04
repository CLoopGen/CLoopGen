#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t * src_data[4];
int i;
uint32_t *d32;

void init_vars() {
    size_t total_size = 1 << 20; // 1MB of data
    size_t num_elements = total_size / sizeof(uint32_t);

    // Allocate d32 with proper alignment for uint32_t
    d32 = (uint32_t*)aligned_alloc(_Alignof(uint32_t), num_elements * sizeof(uint32_t));

    for (int j = 0; j < 4; j++) {
        src_data[j] = (uint8_t*)malloc(num_elements * sizeof(uint32_t));
    }

    // Initialize source data to avoid undefined behavior
    for (size_t idx = 0; idx < num_elements * sizeof(uint32_t); idx++) {
        src_data[1][idx] = (uint8_t)(idx & 0xFF);
    }

    // Ensure loop bounds are safe: i < 256, so we require at least 256 elements
    if (num_elements < 256) {
        // This should not happen with 1MB, but ensure safety
        abort();
    }
}