#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *block;
uint8_t *pixels;
ptrdiff_t line_size;
int h;
int i;
int a1;
int b1;
int a0;
int b0;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB total data
static uint8_t block_data[DATA_SIZE];
static uint8_t pixels_data[DATA_SIZE];

void init_vars() {
    line_size = 32768; // 32 KB per line, typical cache-friendly size
    h = DATA_SIZE / line_size / 2; // ensures we don't exceed data bounds with +2 step
    if (h > DATA_SIZE / line_size) h = DATA_SIZE / line_size & ~1; // ensure even and safe

    // Initialize pointers to beginning of static arrays
    block = block_data;
    pixels = pixels_data;

    // Ensure that within loop, pixels[0], [1], [2] are always valid
    // Each iteration accesses pixels[0..2], and we have h iterations stepping by 2 lines
    // So total lines accessed: h * 2 (since i += 2), each line_size apart

    // Initialize scalar variables
    a0 = 10;
    b0 = 20;
    a1 = 0;
    b1 = 0;
    i = 0;

    // Initialize pixel data to avoid undefined behavior
    for (size_t i = 0; i < DATA_SIZE; ++i) {
        pixels_data[i] = i & 0xFF;
        block_data[i] = 0;
    }
}