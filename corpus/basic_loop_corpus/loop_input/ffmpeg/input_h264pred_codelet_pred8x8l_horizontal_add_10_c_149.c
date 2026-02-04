#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
uint16_t *pix;
int32_t *block;

uint16_t *pix_data;
int32_t *block_data;

void init_vars() {
    const size_t total_data_size = 1 << 20; // 1MB of input data for ~0.01 sec runtime estimate
    const int num_iterations = 8;
    const int pixels_per_row = 8;
    const int block_elements = num_iterations * pixels_per_row;

    stride = 16; // chosen to avoid overlap and allow padding

    // Allocate pix with padding: we access pix[-1], so need at least one element before start
    pix_data = aligned_alloc(64, (total_data_size / sizeof(uint16_t) + stride * num_iterations + 16) * sizeof(uint16_t));
    if (!pix_data) exit(1);

    block_data = aligned_alloc(64, block_elements * sizeof(int32_t));
    if (!block_data) exit(1);

    // Initialize block data with non-zero values
    for (int i = 0; i < block_elements; i++) {
        block_data[i] = (i % 7) * 3 - 4;
    }

    // Set initial pix pointer to leave room for pix[-1]
    pix = pix_data + 1;
    // Initialize base pixel values
    for (int i = 0; i < total_data_size / sizeof(uint16_t); i++) {
        pix_data[i] = (i % 251) + 10; // small positive values
    }

    block = block_data;
}