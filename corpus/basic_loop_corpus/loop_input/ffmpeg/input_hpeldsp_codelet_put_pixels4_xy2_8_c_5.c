#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t *block;
uint8_t *pixels;
ptrdiff_t line_size;
int h;
int i;
uint32_t l0;
uint32_t h0;
uint32_t l1;
uint32_t h1;

static uint8_t *block_data;
static uint8_t *pixels_data;
static size_t total_data_size;

void init_vars() {
    // Aim for ~64MB of data to ensure loop runs long enough (~0.01 sec on modern CPU)
    total_data_size = 64 * 1024 * 1024;
    line_size = 1024; // typical cache-line aligned width
    h = (total_data_size / line_size) & ~1; // ensure even height, multiple of 2

    // Allocate buffers with padding to prevent out-of-bounds access
    block_data = calloc(total_data_size + 2 * line_size, 1);
    pixels_data = calloc(total_data_size + 2 * line_size, 1);

    if (!block_data || !pixels_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize pointers
    block = block_data;
    pixels = pixels_data;

    // Initialize scalar variables
    l0 = 33686018UL;
    h0 = 0;
    l1 = 0;
    h1 = 0;

    // Touch memory to ensure it's mapped in, avoid first-touch overhead
    for (size_t i = 0; i < total_data_size; i += 4096) {
        volatile uint8_t a = pixels_data[i];
        volatile uint8_t b = block_data[i];
        (void)a; (void)b;
    }
}