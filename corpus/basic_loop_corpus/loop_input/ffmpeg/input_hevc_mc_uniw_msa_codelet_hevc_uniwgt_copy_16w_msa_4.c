#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    const int block_height = 1024;

    src_stride = 1024;
    dst_stride = 1024;
    height = block_height & ~0x3; // Ensure divisible by 4

    size_t src_size = height * src_stride;
    size_t dst_size = height * dst_stride;

    // Allocate large buffers with padding to avoid edge faults
    src_buffer = aligned_alloc(64, src_size + 64);
    dst_buffer = aligned_alloc(64, dst_size + 64);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffers
    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    memset(dst_buffer, 0, dst_size);

    // Assign external pointers
    src = src_buffer;
    dst = dst_buffer;

    loop_cnt = 0; // Will be set in loop
}

// Ensure variables are defined at file scope
uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;