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
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec estimate
    size_t alignment = 32;

    height = 8192;
    src_stride = 8192;
    dst_stride = 8192;

    total_src_size = height * src_stride + (src_stride * 2);
    total_dst_size = height * dst_stride + (dst_stride * 2);

    int ret;
    ret = posix_memalign((void**)&src_buffer, alignment, total_src_size);
    if (ret != 0) {
        fprintf(stderr, "Failed to allocate src_buffer\n");
        exit(1);
    }

    ret = posix_memalign((void**)&dst_buffer, alignment, total_dst_size);
    if (ret != 0) {
        fprintf(stderr, "Failed to allocate dst_buffer\n");
        exit(1);
    }

    src = src_buffer + src_stride;
    dst = dst_buffer + dst_stride;

    for (size_t i = 0; i < total_src_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < total_dst_size; i++) {
        dst_buffer[i] = 0;
    }
}