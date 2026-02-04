#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint8_t *src;
int16_t *block;
uint8_t pix[8];
int stride;

uint8_t *src_buffer;
int16_t *block_buffer;

void init_vars() {
    stride = 16;
    for (i = 0; i < 8; i++) {
        pix[i] = (uint8_t)(i * 31 + 17);
    }

    size_t src_size = 256 * 1024 * 1024;
    src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    block_buffer = (int16_t*)aligned_alloc(32, 64 * sizeof(int16_t) * (src_size / (8 * stride)));

    if (!src_buffer || !block_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < src_size; j++) {
        src_buffer[j] = (uint8_t)(j % 256);
    }
    for (int j = 0; j < 64; j++) {
        block_buffer[j] = (int16_t)(j * 13 - 64);
    }

    src = src_buffer;
    block = block_buffer;
}