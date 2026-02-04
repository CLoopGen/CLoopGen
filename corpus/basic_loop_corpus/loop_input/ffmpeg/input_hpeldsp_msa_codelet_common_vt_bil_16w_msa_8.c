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
static size_t total_src_size;
static size_t total_dst_size;

void init_vars() {
    const uint32_t data_size = 64 * 1024 * 1024; // 64 MB for substantial workload
    height = 255; // Ensures (height >> 3) is about 31-32, avoids zero, valid shift
    src_stride = 1024;
    dst_stride = 1024;

    total_src_size = ((size_t)(height >> 3) * 8 * (size_t)src_stride) + 8 * (size_t)src_stride;
    total_dst_size = ((size_t)(height >> 3) * 8 * (size_t)dst_stride) + 8 * (size_t)dst_stride;

    if ((src_buffer = aligned_alloc(64, total_src_size)) == NULL) abort();
    if ((dst_buffer = aligned_alloc(64, total_dst_size)) == NULL) abort();

    src = src_buffer;
    dst = dst_buffer;

    for (size_t i = 0; i < total_src_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < total_dst_size; i++) {
        dst_buffer[i] = 0;
    }
}