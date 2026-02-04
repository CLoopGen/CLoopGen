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
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB for sufficient runtime (~0.01 sec on modern CPU)

    // Allocate source and destination buffers
    src_buffer = (uint8_t*)aligned_alloc(32, total_data_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, total_data_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffer contents
    for (size_t i = 0; i < total_data_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }

    // Set stride and height parameters
    src_stride = 1024;
    dst_stride = 1024;
    height = 4096; // Ensures (height >> 2) iterations, each advancing 4 rows

    // Validate dimensions fit within allocated buffers
    if (((size_t)(height * src_stride)) > total_data_size ||
        ((size_t)(height * dst_stride)) > total_data_size) {
        fprintf(stderr, "Buffer overflow risk avoided\n");
        exit(1);
    }

    // Initialize pointers to start of buffers
    src = src_buffer;
    dst = dst_buffer;

    // Ensure loop_count is initialized properly in loop (via loop_count = height >> 2)
}