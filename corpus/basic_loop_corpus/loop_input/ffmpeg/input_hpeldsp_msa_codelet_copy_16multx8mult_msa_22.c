#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t width;
int32_t cnt;
int32_t loop_cnt;
uint8_t *src_tmp;
uint8_t *dst_tmp;

static uint8_t *internal_src;
static uint8_t *internal_dst;

void init_vars() {
    width = 1024;
    height = 1024;
    src_stride = 1024;
    dst_stride = 1024;

    size_t src_size = (size_t)height * (size_t)src_stride;
    size_t dst_size = (size_t)height * (size_t)dst_stride;

    internal_src = (uint8_t*)aligned_alloc(64, src_size);
    internal_dst = (uint8_t*)aligned_alloc(64, dst_size);

    if (!internal_src || !internal_dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = internal_src;
    dst = internal_dst;

    for (size_t i = 0; i < src_size; ++i) {
        internal_src[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < dst_size; ++i) {
        internal_dst[i] = 0;
    }

    cnt = 0;
    loop_cnt = 0;
    src_tmp = NULL;
    dst_tmp = NULL;
}