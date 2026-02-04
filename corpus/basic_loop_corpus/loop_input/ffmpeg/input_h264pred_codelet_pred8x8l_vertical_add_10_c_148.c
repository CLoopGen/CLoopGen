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
    const size_t data_size = 256 * 1024 * 1024; // ~256MB total data
    const size_t pix_elements = data_size / (sizeof(uint16_t) + sizeof(int32_t)) / 9 * 8;
    const size_t block_elements = pix_elements;

    pix_data = aligned_alloc(32, pix_elements * sizeof(uint16_t));
    block_data = aligned_alloc(32, block_elements * sizeof(int32_t));

    if (!pix_data || !block_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < pix_elements; idx++) {
        pix_data[idx] = (uint16_t)(idx % 32768);
    }
    for (size_t idx = 0; idx < block_elements; idx++) {
        block_data[idx] = (int32_t)(idx % 65536);
    }

    stride = 1;
    pix = pix_data;
    block = block_data;
}