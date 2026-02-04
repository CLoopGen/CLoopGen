#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t width;
uint8_t *src_tmp;
uint8_t *dst_tmp;
uint32_t loop_cnt;
uint32_t cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    width = 1920;
    height = 1080;
    src_stride = 1920;
    dst_stride = 1920;

    size_t src_size = (size_t)src_stride * height;
    size_t dst_size = (size_t)dst_stride * height;

    src_buffer = aligned_alloc(32, src_size);
    dst_buffer = aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(src_buffer, 0x5A, src_size);
    memset(dst_buffer, 0, dst_size);

    src = src_buffer;
    dst = dst_buffer;
    src_tmp = NULL;
    dst_tmp = NULL;
    loop_cnt = 0;
    cnt = 0;
}