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
static size_t total_data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

void init_vars() {
    src_stride = 64;
    dst_stride = 64;
    height = 1048576; // ensures (height >> 1) iterations, large enough for desired runtime

    size_t src_size = (size_t)(height + 2) * (size_t)src_stride;
    size_t dst_size = (size_t)(height + 2) * (size_t)dst_stride;

    src_buffer = aligned_alloc(64, src_size);
    dst_buffer = aligned_alloc(64, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer + src_stride;
    dst = dst_buffer + dst_stride;

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_buffer[i] = 0;
    }
}