#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *dst;
ptrdiff_t dst_stride;
uint8_t *src;
ptrdiff_t src_stride;
int height;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_src_size;
static size_t total_dst_size;

void init_vars() {
    // Aim for approximately 64MB of data to ensure loop runs ~0.01s on modern CPU
    // Using 4 rows processed per iteration (>> 2), choose height and width accordingly
    int width = 2048;
    height = 16384;  // Total height, will be divided by 4 in loop count

    // Stride is typically aligned; use width with some padding for realism
    src_stride = width + 16;  // Add padding to simulate real-world alignment
    dst_stride = width + 16;

    total_src_size = height * (size_t)src_stride;
    total_dst_size = height * (size_t)dst_stride;

    // Allocate buffers with proper alignment
    src_buffer = aligned_alloc(32, total_src_size);
    dst_buffer = aligned_alloc(32, total_dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source buffer with non-zero data to make analysis meaningful
    for (size_t i = 0; i < total_src_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    // Zero out destination
    memset(dst_buffer, 0, total_dst_size);

    // Assign the pointers
    src = src_buffer;
    dst = dst_buffer;

    // Ensure loop_cnt is initialized correctly in loop: loop_cnt = (height >> 2)
    // So we don't modify loop_cnt here — it will be set by the loop function
}

// Cleanup function to avoid memory leaks (not called but good practice to define)
void cleanup_vars() {
    free(src_buffer);
    free(dst_buffer);
}