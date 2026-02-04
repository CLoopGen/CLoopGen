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
    const size_t data_size = 1 << 20; // 1MB of input data for pix (adjustable)
    const int block_elements = 64; // Enough to cover block[56] with margin

    stride = 8; // Stride value chosen to be reasonable for 2D access pattern
    pix_data = (uint16_t*)aligned_alloc(64, data_size);
    block_data = (int32_t*)aligned_alloc(64, block_elements * sizeof(int32_t));

    if (!pix_data || !block_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / sizeof(uint16_t); idx++) {
        pix_data[idx] = (uint16_t)(idx % 32768);
    }

    for (int idx = 0; idx < block_elements; idx++) {
        block_data[idx] = idx * 100;
    }

    pix = pix_data;
    block = block_data;
}