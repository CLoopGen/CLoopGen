#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int i;
int E;
ptrdiff_t step;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    // Set constants
    A = 17;  // Arbitrary coefficient
    E = 35;  // Another arbitrary coefficient
    h = 1024 * 1024 / sizeof(uint8_t); // ~1MB of data processed
    stride = 4; // Each row advances by 4 bytes
    step = 1;   // step used in indexing within a row

    // Allocate buffers with extra space to avoid out-of-bounds access
    size_t total_size = (h * stride) + stride + 8; // Add padding for safety
    dst_buffer = (uint8_t*)aligned_alloc(64, total_size);
    src_buffer = (uint8_t*)aligned_alloc(64, total_size);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data to prevent undefined behavior
    for (size_t idx = 0; idx < total_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx % 251);
    }

    // Initialize destination pointers
    dst = dst_buffer;
    src = src_buffer;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}