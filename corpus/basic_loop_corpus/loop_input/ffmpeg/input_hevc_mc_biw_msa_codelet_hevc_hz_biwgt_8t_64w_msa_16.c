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
uint8_t *src0_ptr_tmp;
uint8_t *dst_tmp;
int16_t *src1_ptr_tmp;
uint32_t loop_cnt;
uint32_t cnt;

static uint8_t *src0_data;
static int16_t *src1_data;
static uint8_t *dst_data;

void init_vars() {
    height = 256;
    src_stride = 1024;
    src2_stride = 512;
    dst_stride = 1024;

    size_t src0_size = (size_t)(height) * src_stride;
    size_t src1_size = (size_t)(height) * src2_stride / sizeof(int16_t);
    size_t dst_size = (size_t)(height) * dst_stride;

    src0_data = aligned_alloc(32, src0_size);
    src1_data = aligned_alloc(32, src1_size * sizeof(int16_t));
    dst_data = aligned_alloc(32, dst_size);

    src0_ptr = src0_data;
    src1_ptr = src1_data;
    dst = dst_data;

    for (size_t i = 0; i < src0_size; i++) {
        src0_data[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < src1_size; i++) {
        src1_data[i] = (int16_t)(i & 0xFFFF);
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_data[i] = 0;
    }
}