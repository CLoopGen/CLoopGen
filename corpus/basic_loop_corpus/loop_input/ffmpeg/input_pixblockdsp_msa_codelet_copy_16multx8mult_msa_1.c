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
int32_t cnt;
int32_t loop_cnt;
uint8_t *src_tmp;
uint8_t *dst_tmp;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    width = 1024;
    height = 1024;
    src_stride = 1024;
    dst_stride = 1024;

    size_t src_size = (size_t)height * (size_t)src_stride;
    size_t dst_size = (size_t)height * (size_t)dst_stride;

    src_buffer = aligned_alloc(64, src_size);
    dst_buffer = aligned_alloc(64, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(src_buffer, 0x5A, src_size);
    memset(dst_buffer, 0, dst_size);

    src = src_buffer;
    dst = dst_buffer;
}