#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    size_t total_data_size = 64 * 1024 * 1024; // 64 MB for substantial computation (~0.01 sec estimate)
    size_t buffer_size = total_data_size + 16 * 1024; // Extra to allow for stride and alignment

    src_buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, buffer_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src_stride = 2048;
    dst_stride = 2048;

    height = 512;

    src = src_buffer;
    dst = dst_buffer;

    cnt = 0;
}

__attribute__((destructor))
static void cleanup() {
    free(src_buffer);
    free(dst_buffer);
}