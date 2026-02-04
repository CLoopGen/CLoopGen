#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
uint8_t *pix;
int16_t *block;

uint8_t *pix_data;
int16_t *block_data;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB
    pix_data = (uint8_t*)aligned_alloc(32, data_size);
    block_data = (int16_t*)aligned_alloc(32, data_size);

    if (!pix_data || !block_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        pix_data[idx] = (uint8_t)(idx & 0xFF);
    }
    for (size_t idx = 0; idx < data_size / sizeof(int16_t); idx++) {
        block_data[idx] = (int16_t)(idx & 0x7FF);
    }

    stride = 64;
    pix = pix_data;
    block = block_data;
}

__attribute__((constructor))
void initialize() {
    init_vars();
}