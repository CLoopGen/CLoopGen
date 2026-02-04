#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
    height = 4096;
    dst_stride = 4096;
    src_stride = 4096;

    total_src_size = (size_t)height * (size_t)src_stride;
    total_dst_size = (size_t)height * (size_t)dst_stride;

    src_buffer = aligned_alloc(64, total_src_size);
    dst_buffer = aligned_alloc(64, total_dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    for (size_t i = 0; i < total_src_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < total_dst_size; ++i) {
        dst_buffer[i] = 0;
    }
}