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
static int allocated_size = 16 * 1024 * 1024; // ~16MB per buffer

void init_vars() {
    src_stride = 4096;
    dst_stride = 4096;
    height = 8192;

    size_t src_size = (size_t)(height * 2) * src_stride;
    size_t dst_size = (size_t)(height * 2) * dst_stride;

    src_buffer = aligned_alloc(32, src_size);
    dst_buffer = aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
    loop_cnt = 0;
}