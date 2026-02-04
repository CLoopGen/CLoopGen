#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *src0_ptr;
int32_t src_stride;
int16_t *src1_ptr;
int32_t src2_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;

static uint8_t *src0_buf;
static int16_t *src1_buf;
static uint8_t *dst_buf;

void init_vars() {
    height = 16384;

    src_stride = 64;
    src2_stride = 32;
    dst_stride = 64;

    size_t src0_size = (size_t)height * (size_t)src_stride;
    size_t src1_size = (size_t)height * (size_t)src2_stride / sizeof(int16_t);
    size_t dst_size = (size_t)height * (size_t)dst_stride;

    src0_buf = (uint8_t*)aligned_alloc(64, src0_size);
    src1_buf = (int16_t*)aligned_alloc(64, src1_size * sizeof(int16_t));
    dst_buf = (uint8_t*)aligned_alloc(64, dst_size);

    if (!src0_buf || !src1_buf || !dst_buf) {
        exit(1);
    }

    for (size_t i = 0; i < src0_size; i++) {
        src0_buf[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < src1_size; i++) {
        src1_buf[i] = (int16_t)(i & 0x7FF);
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_buf[i] = 0;
    }

    src0_ptr = src0_buf;
    src1_ptr = src1_buf;
    dst = dst_buf;

    loop_cnt = 0;
}