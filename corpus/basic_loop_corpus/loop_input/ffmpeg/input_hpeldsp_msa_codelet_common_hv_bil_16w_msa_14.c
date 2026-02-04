#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
uint8_t height;
uint8_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_src_size;
static size_t total_dst_size;

void init_vars() {
    // Set image dimensions: aim for ~64MB of source data to ensure measurable runtime
    // Use 4096x4096 pixels as a large but reasonable size, height must be multiple of 8 due to >>3
    uint16_t img_width = 4096;
    height = 4096;

    src_stride = (int32_t)(img_width);
    dst_stride = (int32_t)(img_width);

    size_t num_blocks = height / 8;
    total_src_size = (size_t)(src_stride) * height;
    total_dst_size = (size_t)(dst_stride) * height;

    // Allocate aligned memory to avoid issues and improve performance
    src_buffer = (uint8_t*)aligned_alloc(32, total_src_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, total_dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    // Initialize buffers with predictable patterns
    for (size_t i = 0; i < total_src_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < total_dst_size; ++i) {
        dst_buffer[i] = 0;
    }

    // Assign pointers
    src = src_buffer;
    dst = dst_buffer;

    // Ensure loop_cnt is initialized correctly in loop()
    loop_cnt = 0;
}

// Cleanup function to prevent memory leaks (not called here but good practice)
// Caller must ensure proper cleanup elsewhere if needed