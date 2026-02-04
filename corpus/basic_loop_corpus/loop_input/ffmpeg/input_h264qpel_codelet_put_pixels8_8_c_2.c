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
int h;
int i;

static uint8_t *block_data;
static uint8_t *pixels_data;
static size_t total_size;
static int height;

void init_vars() {
    height = 4096;
    line_size = 512;
    h = height;
    total_size = (size_t)height * (size_t)line_size;

    block_data = aligned_alloc(64, total_size);
    pixels_data = aligned_alloc(64, total_size);

    if (!block_data || !pixels_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; ++idx) {
        pixels_data[idx] = (uint8_t)(idx & 0xFF);
        block_data[idx] = 0;
    }

    block = block_data;
    pixels = pixels_data;
}