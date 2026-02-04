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
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    const int alignment = 32;

    // Allocate aligned buffers to allow for vectorization and avoid cache issues
    if (posix_memalign((void**)&src_buffer, alignment, data_size) != 0 ||
        posix_memalign((void**)&dst_buffer, alignment, data_size) != 0) {
        exit(1);
    }

    // Initialize buffer contents to avoid undefined behavior
    for (size_t i = 0; i < data_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;

    src_stride = 1024;  // Simulate row stride in a large image-like structure
    dst_stride = 1024;

    height = 4096; // Ensures loop_count = height >> 2 = 1024 iterations
}

// Cleanup function to avoid memory leaks (not required by problem but good practice)
void free_vars() {
    free(src_buffer);
    free(dst_buffer);
}