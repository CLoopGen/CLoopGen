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
int j;

static uint8_t *block_data;
static uint8_t *pixels_data;

void init_vars() {
    const size_t data_size = 16777216; // 16 MB for ~0.01 sec runtime estimate
    const int alignment = 16;

    // Allocate aligned memory to avoid unaligned access issues and satisfy packed/may_alias usage
    if (posix_memalign((void**)&block_data, alignment, data_size) != 0) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    if (posix_memalign((void**)&pixels_data, alignment, data_size) != 0) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize with deterministic pattern
    for (size_t i = 0; i < data_size; ++i) {
        pixels_data[i] = (uint8_t)(i & 0xFF);
        block_data[i] = 0;
    }

    // Set external pointers
    block = block_data;
    pixels = pixels_data;

    // Configure loop parameters to prevent out-of-bounds access
    line_size = 1024; // reasonable stride, multiple of 4
    h = ((data_size / line_size) - 2) & ~1; // largest even number fitting in allocated space, allows safe pixel/block advancement

    // Ensure h is at least 2 to allow meaningful loop execution
    if (h < 2) {
        h = 2;
    }

    j = 0;
}