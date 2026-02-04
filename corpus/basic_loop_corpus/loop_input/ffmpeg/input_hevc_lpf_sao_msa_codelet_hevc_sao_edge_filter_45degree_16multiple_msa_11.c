#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define TOTAL_BYTES (DATA_SIZE_MB * 1024ULL * 1024)

uint8_t *dst;
int32_t dst_stride;
uint8_t *src;
int32_t src_stride;
int32_t width;
int32_t height;
uint8_t *src_orig;
uint8_t *dst_orig;
int32_t v_cnt;

static uint8_t *internal_src_buffer;
static uint8_t *internal_dst_buffer;

void init_vars() {
    width = 4096;
    height = (TOTAL_BYTES / width + 3) / 4 * 4; // multiple of 4 for loop unrolling
    src_stride = width;
    dst_stride = width;

    size_t src_size = (size_t)src_stride * height;
    size_t dst_size = (size_t)dst_stride * height;

    internal_src_buffer = (uint8_t*)aligned_alloc(64, src_size);
    internal_dst_buffer = (uint8_t*)aligned_alloc(64, dst_size);

    if (!internal_src_buffer || !internal_dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = internal_src_buffer;
    dst = internal_dst_buffer;

    for (size_t i = 0; i < src_size; i++) {
        internal_src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < dst_size; i++) {
        internal_dst_buffer[i] = 0;
    }

    src_orig = NULL;
    dst_orig = NULL;
    v_cnt = 0;
}