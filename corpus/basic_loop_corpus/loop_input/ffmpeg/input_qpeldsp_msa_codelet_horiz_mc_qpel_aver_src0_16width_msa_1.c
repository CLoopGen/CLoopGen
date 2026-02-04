#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint8_t loop_count;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB for sufficient runtime (~0.01 sec)
    const int block_height = 1024;
    const int width = 65536 / sizeof(uint8_t); // Adjusted to fit cache behavior and ensure enough rows

    src_stride = width;
    dst_stride = width;
    height = block_height;

    // Allocate buffers with padding to prevent out-of-bounds access
    src_buffer = aligned_alloc(32, total_data_size + src_stride * 4);
    dst_buffer = aligned_alloc(32, total_data_size + dst_stride * 4);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    // Initialize source data to avoid undefined behavior
    for (size_t i = 0; i < total_data_size; ++i) {
        src_buffer[i] = rand() & 0xFF;
    }
}

// Ensure variables are defined even if not used elsewhere
__attribute__((unused)) static void *force_link[] = { (void*)&src, (void*)&src_stride, (void*)&dst, (void*)&dst_stride, (void*)&height };