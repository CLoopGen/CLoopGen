#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
uint16_t *pix;
int32_t *block;

static uint16_t *pix_buffer;
static int32_t *block_buffer;

void init_vars() {
    const size_t total_data_size = 1 << 20; // 1MB of pixel data
    const int num_iterations = 8;
    const int pixels_per_row = 8;
    const int block_elements_per_iter = 8;

    stride = 16; // Ensure sufficient padding to prevent overflow

    size_t pix_buffer_size = (total_data_size / sizeof(uint16_t)) + abs(stride) * num_iterations;
    size_t block_buffer_size = num_iterations * block_elements_per_iter;

    pix_buffer = aligned_alloc(32, pix_buffer_size * sizeof(uint16_t));
    block_buffer = aligned_alloc(32, block_buffer_size * sizeof(int32_t));

    if (!pix_buffer || !block_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < pix_buffer_size; ++idx) {
        pix_buffer[idx] = (uint16_t)(idx % 65535);
    }
    for (size_t idx = 0; idx < block_buffer_size; ++idx) {
        block_buffer[idx] = (int32_t)(idx % 1000);
    }

    pix = pix_buffer + (abs(stride) * num_iterations / 2); 
    block = block_buffer;
}