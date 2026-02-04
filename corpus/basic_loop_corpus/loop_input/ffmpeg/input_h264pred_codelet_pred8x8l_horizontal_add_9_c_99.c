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
    const size_t total_data_size = 1 << 20; // ~1MB of working data
    const size_t num_iterations = total_data_size / (8 * sizeof(int32_t));
    
    stride = 16; // Ensure sufficient padding between rows

    // Allocate pix buffer: each iteration accesses [0..7], and reads [-1]
    // So we need at least (num_iterations * stride) elements with padding on left and right
    const size_t pix_rows = num_iterations + 1;
    const size_t pix_row_size = stride + 2; // +1 left for pix[-1], +1 right for safety
    pix_buffer = aligned_alloc(32, pix_rows * pix_row_size * sizeof(uint16_t));
    if (!pix_buffer) exit(1);

    // block needs 8 elements per iteration
    block_buffer = aligned_alloc(32, num_iterations * 8 * sizeof(int32_t));
    if (!block_buffer) exit(1);

    // Initialize all data to predictable values
    for (size_t idx = 0; idx < pix_rows * pix_row_size; idx++) {
        pix_buffer[idx] = (uint16_t)(idx % 257);
    }
    for (size_t idx = 0; idx < num_iterations * 8; idx++) {
        block_buffer[idx] = (int32_t)(idx % 100 - 50);
    }

    // Set initial pix and block pointers
    pix = pix_buffer + 1; // +1 to allow pix[-1] safely at first row
    block = block_buffer;
}