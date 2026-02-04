#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int h;
int A;
int i;
int bias;
int E;
ptrdiff_t step;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64MB for sufficient runtime (~0.01s on modern CPU)
    const int width = 4; // Since we access dst[0..3] and src[0..3], step + 3 must be valid

    h = total_data_size / width;
    stride = width;
    step = width;
    A = 17;
    E = 31;
    bias = 128;

    // Allocate buffers with extra padding to prevent out-of-bounds access
    dst_buffer = (uint8_t*)aligned_alloc(32, total_data_size + stride * h + step + 8);
    src_buffer = (uint8_t*)aligned_alloc(32, total_data_size + stride * h + step + 8);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffers with predictable data
    for (size_t i = 0; i < total_data_size + step + 8; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = (uint8_t)((i * 7) & 0xFF);
    }

    // Set pointers to valid starting positions within buffers
    dst = dst_buffer;
    src = src_buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(dst_buffer);
    free(src_buffer);
}