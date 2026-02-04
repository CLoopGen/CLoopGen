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

void init_vars() {
    size_t total_size = 64 * 1024 * 1024; // 64 MB to ensure ~0.01 sec runtime
    size_t buffer_size = total_size + 64;

    src_buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, buffer_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < buffer_size; ++i) {
        src_buffer[i] = rand() & 0xFF;
        dst_buffer[i] = 0;
    }

    src_stride = 4096; // Simulate a large stride for block processing
    dst_stride = 4096;
    height = 255; // Ensures loop_cnt = 255 >> 3 = 31 iterations

    src = src_buffer + (rand() % (src_stride - 8));
    dst = dst_buffer + (rand() % (dst_stride - 8));

    loop_cnt = 0;
}