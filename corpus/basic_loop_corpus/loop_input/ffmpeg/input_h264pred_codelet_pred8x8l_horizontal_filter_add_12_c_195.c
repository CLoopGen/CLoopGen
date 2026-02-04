#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint16_t *src;
int32_t *block;
uint16_t pix[8];
int stride;

uint16_t *src_data;
int32_t *block_data;

void init_vars() {
    const size_t total_size = 1 << 20; // 1MB working set
    stride = 8;

    src_data = aligned_alloc(32, total_size);
    block_data = aligned_alloc(32, total_size);

    src = src_data;
    block = block_data;

    for (int j = 0; j < 8; j++) {
        pix[j] = (uint16_t)(j + 1) * 10;
    }

    size_t num_blocks = total_size / (8 * sizeof(int32_t));
    size_t src_elements = (total_size / sizeof(uint16_t)) / 8;
    if (src_elements > num_blocks) src_elements = num_blocks;

    for (size_t j = 0; j < src_elements * 8; j++) {
        src_data[j] = 0;
    }
    for (size_t j = 0; j < num_blocks * 8; j++) {
        block_data[j] = (int32_t)(j % 256) - 128;
    }
}