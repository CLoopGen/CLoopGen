#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint8_t *src;
int16_t *block;
uint8_t pix[8];
int stride;

uint8_t *src_data;
int16_t *block_data;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of output data
    stride = 16;

    src_data = aligned_alloc(32, data_size);
    block_data = aligned_alloc(32, data_size * sizeof(int16_t));

    if (!src_data || !block_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        src_data[idx] = (uint8_t)(idx % 256);
        block_data[idx] = (int16_t)(idx % 512 - 256);
    }

    for (int j = 0; j < 8; j++) {
        pix[j] = (uint8_t)(j + 1);
    }

    src = src_data;
    block = block_data;
}