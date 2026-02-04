#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t cnt;
uint8_t *dst_dup;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static uint8_t *dst_dup_buffer;

void init_vars() {
    const int total_data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    src_stride = 2048;
    dst_stride = 2048;
    height = 8192;

    size_t src_size = (size_t)height * (size_t)src_stride;
    size_t dst_size = (size_t)height * (size_t)dst_stride * 2; // account for both dst and dst_dup

    src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, dst_size);
    dst_dup_buffer = (uint8_t*)aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer || !dst_dup_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(src_buffer, 0x5A, src_size);
    memset(dst_buffer, 0, dst_size);
    memset(dst_dup_buffer, 0, dst_size);

    src = src_buffer;
    dst = dst_buffer;
    dst_dup = dst_dup_buffer;

    cnt = height / 8;
}