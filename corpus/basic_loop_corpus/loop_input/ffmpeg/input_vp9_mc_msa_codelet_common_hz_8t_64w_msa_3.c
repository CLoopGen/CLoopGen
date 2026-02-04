#include <stdlib.h>
#include <stdint.h>
#include <string.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    // Set dimensions for meaningful performance (target ~0.01s)
    // Use moderate height and stride to simulate a typical image processing scenario
    height = 8192;
    src_stride = 16384;  // Wide rows to increase data volume
    dst_stride = 16384;
    
    // Allocate large buffers to ensure sufficient data size (~134MB total)
    src_buffer = (uint8_t*)aligned_alloc(64, (size_t)height * src_stride);
    dst_buffer = (uint8_t*)aligned_alloc(64, (size_t)height * dst_stride);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    // Initialize buffers with predictable pattern to avoid undefined behavior
    for (int i = 0; i < height * src_stride; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    memset(dst_buffer, 0, (size_t)height * dst_stride);

    // Assign pointers
    src = src_buffer;
    dst = dst_buffer;

    loop_cnt = 0;
}

// Cleanup function to avoid memory leaks (not called here but implied usage)
// Application should free src_buffer and dst_buffer after loop execution