#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

uint8_t *block;
uint8_t *pixels;
ptrdiff_t line_size;
int h;
int i;

#define DATA_SIZE (128 << 20) // 128 MB

static uint8_t *block_data;
static uint8_t *pixels_data;

void init_vars() {
    const int pixel_stride = 8; // Each iteration accesses 8 bytes via uint64_t
    const int block_height = 8192; // Adjust height for sufficient workload

    line_size = pixel_stride;
    h = block_height;

    // Allocate memory with padding to avoid out-of-bounds access
    block_data = aligned_alloc(64, DATA_SIZE);
    pixels_data = aligned_alloc(64, DATA_SIZE);

    if (!block_data || !pixels_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize pointers
    block = block_data;
    pixels = pixels_data;
}

__attribute__((destructor))
static void cleanup() {
    free(block_data);
    free(pixels_data);
}