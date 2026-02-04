#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *dst;
int32_t dst_stride;
uint8_t *src;
int32_t src_stride;
int32_t width;
int32_t height;
uint8_t *src_orig;
uint8_t *dst_orig;
int32_t h_cnt;
int32_t v_cnt;

static uint8_t *internal_src_buffer;
static uint8_t *internal_dst_buffer;

void init_vars() {
    width = 1024;
    height = 1024;
    src_stride = width;
    dst_stride = width;

    size_t src_size = (size_t)src_stride * height;
    size_t dst_size = (size_t)dst_stride * height;

    internal_src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    internal_dst_buffer = (uint8_t*)aligned_alloc(32, dst_size);

    if (!internal_src_buffer || !internal_dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(internal_src_buffer, 0x5A, src_size);
    memset(internal_dst_buffer, 0, dst_size);

    src_orig = internal_src_buffer;
    dst_orig = internal_dst_buffer;
    src = src_orig;
    dst = dst_orig;
    h_cnt = 0;
    v_cnt = 0;
}