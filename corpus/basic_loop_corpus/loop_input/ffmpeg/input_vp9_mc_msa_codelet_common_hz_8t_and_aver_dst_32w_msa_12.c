#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for substantial workload (~0.01 sec on modern CPU)
    src_stride = 64;
    dst_stride = 64;
    height = data_size / 64; // ensures total traversal matches allocated size

    src_buffer = aligned_alloc(64, data_size);
    dst_buffer = aligned_alloc(64, data_size);

    if (!src_buffer || !dst_buffer) {
        exit(EXIT_FAILURE);
    }

    src = src_buffer - (height / 2) * src_stride; // center the valid access range
    dst = dst_buffer - (height / 2) * dst_stride;

    for (size_t i = 0; i < data_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}