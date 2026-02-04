#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *src0_ptr;
int32_t src_stride;
int16_t *src1_ptr;
int32_t src2_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t width;
uint8_t *src0_ptr_tmp;
int16_t *src1_ptr_tmp;
uint8_t *dst_tmp;
uint32_t loop_cnt;
uint32_t cnt;

static uint8_t *src0_data;
static int16_t *src1_data;
static uint8_t *dst_data;

void init_vars() {
    width = 1024;
    height = 1024;

    src_stride = width + 32;
    src2_stride = width + 16;
    dst_stride = width + 32;

    size_t src0_size = (size_t)(height + 16) * (size_t)src_stride;
    size_t src1_size = (size_t)(height + 16) * (size_t)src2_stride / sizeof(int16_t) * sizeof(int16_t);
    size_t dst_size = (size_t)(height + 16) * (size_t)dst_stride;

    src0_data = (uint8_t*)aligned_alloc(64, src0_size);
    src1_data = (int16_t*)aligned_alloc(64, src1_size);
    dst_data = (uint8_t*)aligned_alloc(64, dst_size);

    if (!src0_data || !src1_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src0_size; i++) {
        src0_data[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < src1_size / sizeof(int16_t); i++) {
        src1_data[i] = (int16_t)(i & 0x7FF);
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_data[i] = 0;
    }

    src0_ptr = src0_data + 8 * src_stride;
    src1_ptr = src1_data + 8 * (src2_stride / sizeof(int16_t));
    dst = dst_data + 8 * dst_stride;
}