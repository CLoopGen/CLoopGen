#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint16_t *src;
int32_t *block;
uint16_t pix[8];
int stride;

static uint16_t src_buffer[256 * 1024 * 1024]; // ~512 MB of data (each element is 2 bytes, and we have multiple accesses)
static int32_t block_buffer[64 * 1024 * 1024]; // ~256 MB of data (each element is 4 bytes)

void init_vars() {
    stride = 16; // chosen to avoid overlap and align memory access

    // Initialize pix with non-zero values
    for (int j = 0; j < 8; j++) {
        pix[j] = (j + 1) * 10;
    }

    // Set up src to point into the large buffer
    src = src_buffer;

    // Set up block to point into its buffer
    block = block_buffer;

    // Ensure block has enough elements: loop runs 8 times, each time accessing indices 0,8,...,56 -> needs at least 64 elements per iteration
    // Total required: 8 iterations * 64 elements (since block is incremented by 1 each time, and we need offset up to 56)
    size_t total_block_elements_needed = 8 * 64;
    if (sizeof(block_buffer) / sizeof(int32_t) < total_block_elements_needed) {
        // This should not happen given our static allocation
        abort();
    }

    // Initialize block_buffer with sequential values to prevent optimization away
    for (size_t idx = 0; idx < total_block_elements_needed; idx++) {
        block_buffer[idx] = (int32_t)(idx * 3);
    }

    // Similarly initialize src_buffer
    for (size_t idx = 0; idx < sizeof(src_buffer) / sizeof(uint16_t); idx++) {
        src_buffer[idx] = (uint16_t)(idx % 65535);
    }
}