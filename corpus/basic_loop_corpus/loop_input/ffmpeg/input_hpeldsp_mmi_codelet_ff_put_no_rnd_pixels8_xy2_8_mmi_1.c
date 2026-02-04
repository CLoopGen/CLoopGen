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
    // Set image dimensions and line size
    h = 1024;  // Number of rows processed in inner loop
    line_size = 2048;  // Bytes per row (stride)

    // Allocate sufficiently large buffers to meet runtime target (~0.01 sec)
    // Total data size ~ 2MB (two 1MB arrays), which should be sufficient
    block_data = calloc(1, line_size * (h + 4));
    pixels_data = calloc(1, line_size * (h + 4));

    if (!block_data || !pixels_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize pointers
    block = block_data;
    pixels = pixels_data;
}

// Ensure proper cleanup if needed (not required by spec, but safe)
__attribute__((destructor))
static void cleanup() {
    free(block_data);
    free(pixels_data);
}