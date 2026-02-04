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

static uint8_t *src0_data;
static int16_t *src1_data;
static uint8_t *dst_data;

void init_vars() {
    height = 4096;

    size_t src0_row_size = 512;
    size_t src1_row_size = 512;
    size_t dst_row_size = 512;

    src_stride = src0_row_size;
    src2_stride = src1_row_size;
    dst_stride = dst_row_size;

    size_t src0_total_size = (size_t)height * src_stride;
    size_t src1_total_size = (size_t)height * src1_row_size;
    size_t dst_total_size = (size_t)height * dst_row_size;

    src0_data = (uint8_t*)aligned_alloc(64, src0_total_size);
    src1_data = (int16_t*)aligned_alloc(64, src1_total_size);
    dst_data = (uint8_t*)aligned_alloc(64, dst_total_size);

    if (!src0_data || !src1_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src0_total_size; ++i) {
        src0_data[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < src1_total_size; ++i) {
        src1_data[i] = (int16_t)(i & 0xFFFF);
    }
    for (size_t i = 0; i < dst_total_size; ++i) {
        dst_data[i] = 0;
    }

    src0_ptr = src0_data;
    src1_ptr = src1_data;
    dst = dst_data;

    loop_cnt = 0;
}