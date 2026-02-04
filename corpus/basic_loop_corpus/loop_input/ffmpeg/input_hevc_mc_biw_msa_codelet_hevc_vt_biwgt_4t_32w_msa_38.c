#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src0_ptr;
int32_t src_stride;
int16_t *src1_ptr;
int32_t src2_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;
uint8_t *dst_tmp;

static uint8_t *src0_data;
static int16_t *src1_data;
static uint8_t *dst_data;
static uint8_t *dst_tmp_data;

void init_vars() {
    height = 4096;

    int32_t width = 512;

    src_stride = width;
    src2_stride = width;
    dst_stride = width;

    size_t src0_size = (size_t)(height + 2) * src_stride * sizeof(uint8_t);
    size_t src1_size = (size_t)(height + 2) * src2_stride * sizeof(int16_t);
    size_t dst_size = (size_t)(height + 2) * dst_stride * sizeof(uint8_t);
    size_t dst_tmp_size = (size_t)(height + 2) * dst_stride * sizeof(uint8_t);

    src0_data = (uint8_t*)aligned_alloc(32, src0_size);
    src1_data = (int16_t*)aligned_alloc(32, src1_size);
    dst_data = (uint8_t*)aligned_alloc(32, dst_size);
    dst_tmp_data = (uint8_t*)aligned_alloc(32, dst_tmp_size);

    src0_ptr = src0_data + src_stride;
    src1_ptr = src1_data + src2_stride;
    dst = dst_data + dst_stride;
    dst_tmp = dst_tmp_data + dst_stride;

    for (size_t i = 0; i < src0_size / sizeof(uint8_t); ++i) {
        src0_data[i] = rand() % 256;
    }
    for (size_t i = 0; i < src1_size / sizeof(int16_t); ++i) {
        src1_data[i] = rand() % 65536 - 32768;
    }
    for (size_t i = 0; i < dst_size / sizeof(uint8_t); ++i) {
        dst_data[i] = 0;
    }
    for (size_t i = 0; i < dst_tmp_size / sizeof(uint8_t); ++i) {
        dst_tmp_data[i] = 0;
    }

    loop_cnt = 0;
}