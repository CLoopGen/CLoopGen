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
static int data_size;

void init_vars() {
    data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    src_buffer = (uint8_t*)aligned_alloc(32, data_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, data_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src_stride = 1024;
    dst_stride = 1024;
    height = 1024;

    src = src_buffer;
    dst = dst_buffer;

    for (int i = 0; i < data_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }
}