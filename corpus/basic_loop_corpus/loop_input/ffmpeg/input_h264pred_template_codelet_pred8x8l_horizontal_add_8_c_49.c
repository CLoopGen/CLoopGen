#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
uint8_t *pix;
int16_t *block;

uint8_t *pix_buffer;
int16_t *block_buffer;

void init_vars() {
    const size_t total_data_size = 1 << 20; // ~1MB of data for pix (adjustable)
    const int num_iterations = 8;
    const int pixels_per_row = 8;
    
    stride = 64; // chosen to avoid overlap and allow safe access

    // Allocate enough rows: 8 iterations, each advancing by stride
    size_t buffer_size = stride * num_iterations;
    pix_buffer = (uint8_t*)aligned_alloc(64, buffer_size);
    block_buffer = (int16_t*)aligned_alloc(64, num_iterations * pixels_per_row * sizeof(int16_t));

    if (!pix_buffer || !block_buffer) {
        exit(1);
    }

    // Initialize all memory to predictable values
    for (size_t idx = 0; idx < buffer_size; idx++) {
        pix_buffer[idx] = (uint8_t)(idx % 256);
    }
    for (int idx = 0; idx < num_iterations * pixels_per_row; idx++) {
        block_buffer[idx] = (int16_t)(idx % 32 - 16);
    }

    // Set pointers to valid starting positions
    // Ensure pix[-1] is accessible -> start pix at offset 1
    pix = pix_buffer + 1;
    block = block_buffer;
}