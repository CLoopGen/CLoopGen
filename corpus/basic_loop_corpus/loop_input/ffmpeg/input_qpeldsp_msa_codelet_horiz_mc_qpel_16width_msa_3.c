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
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB for substantial runtime (~0.01 sec on modern CPU)
    const int pixel_height = 4096;
    const int pixel_width = 4096;

    src_stride = pixel_width;
    dst_stride = pixel_width;
    height = pixel_height;

    size_t src_size = (size_t)src_stride * (size_t)height;
    size_t dst_size = (size_t)dst_stride * (size_t)height;

    src_buffer = aligned_alloc(32, src_size);
    dst_buffer = aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size; ++i) {
        src_buffer[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < dst_size; ++i) {
        dst_buffer[i] = rand() & 0xFF;
    }

    src = src_buffer;
    dst = dst_buffer;
}