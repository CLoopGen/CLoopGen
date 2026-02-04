#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t *block;
uint8_t *pixels;
ptrdiff_t line_size;
int i;

#define DATA_SIZE (128 * 1024 * 1024)  // 128 MB total data
static uint8_t *block_data;
static uint8_t *pixels_data;

void init_vars() {
    line_size = 16;  // Ensure alignment and safe access for 8 iterations

    block_data = aligned_alloc(16, DATA_SIZE);
    pixels_data = aligned_alloc(16, DATA_SIZE);

    if (!block_data || !pixels_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        pixels_data[idx] = (uint8_t)(idx % 256);
        block_data[idx] = 0;
    }

    block = block_data;
    pixels = pixels_data;
}