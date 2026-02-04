#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
int size;
uint8_t *left;
int bottom_left_size;
uint32_t pix;

void init_vars() {
    size = 64 * 1024 * 1024;  // 64 MB to target ~0.01 sec runtime
    bottom_left_size = 1024;  // Arbitrary offset, within bounds
    pix = 0xDEADBEEF;         // Arbitrary pattern to write

    // Ensure that (size - bottom_left_size) is positive and multiple of 4 friendly
    if (bottom_left_size >= size) {
        bottom_left_size = size - 4;
    }

    // Allocate left with enough space: need up to (size + bottom_left_size + (size - bottom_left_size))
    // That is: size + bottom_left_size + i_max -> i_max = size - bottom_left_size - 4 (last iteration)
    // So total offset: size + bottom_left_size + (size - bottom_left_size - 4) = 2*size - 4
    size_t total_size = 2 * size;
    left = (uint8_t*)aligned_alloc(16, total_size);
    if (!left) {
        exit(1);
    }

    // Initialize the entire buffer to zero
    for (size_t idx = 0; idx < total_size; ++idx) {
        left[idx] = 0;
    }
}