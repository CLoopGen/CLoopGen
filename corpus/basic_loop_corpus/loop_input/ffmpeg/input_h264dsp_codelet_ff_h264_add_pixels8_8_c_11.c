#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int stride;
int i;
uint8_t *dst;
int16_t *src;

static uint8_t *dst_buffer;
static int16_t *src_buffer;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data
    const size_t num_elements = data_size / sizeof(int16_t);
    const size_t loop_iterations = num_elements / 8; // Each loop consumes 8 elements

    stride = 8; // Advance dst by 8 bytes per iteration

    // Allocate buffers with extra space to avoid overflow
    dst_buffer = (uint8_t*)aligned_alloc(32, data_size + stride * loop_iterations);
    src_buffer = (int16_t*)aligned_alloc(32, data_size + 8 * sizeof(int16_t));

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffers to zero to ensure defined behavior
    for (size_t idx = 0; idx < data_size; ++idx) {
        dst_buffer[idx] = 0;
        ((uint8_t*)src_buffer)[idx] = rand() & 0xFF;
    }

    // Initialize pointers
    dst = dst_buffer;
    src = src_buffer;

    // Ensure the loop runs exactly over valid data
    i = 0;
}

// Force definition to be included even if not referenced directly
__attribute__((constructor))
static void constructor_init() {
    init_vars();
}