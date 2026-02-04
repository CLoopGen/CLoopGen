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

static uint8_t *src0_base;
static int16_t *src1_base;
static uint8_t *dst_base;

void init_vars() {
    const int32_t width = 2048;  
    height = 131072;  

    src_stride = width;
    src2_stride = width / 2;
    dst_stride = width;

    size_t src0_size = (size_t)height * (size_t)src_stride;
    size_t src1_size = (size_t)height * (size_t)src2_stride;
    size_t dst_size = (size_t)height * (size_t)dst_stride;

    src0_base = (uint8_t*)aligned_alloc(32, src0_size);
    src1_base = (int16_t*)aligned_alloc(32, src1_size);
    dst_base = (uint8_t*)aligned_alloc(32, dst_size);

    if (!src0_base || !src1_base || !dst_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src0_size; i++) {
        src0_base[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < src1_size / sizeof(int16_t); i++) {
        ((int16_t*)src1_base)[i] = (int16_t)(i & 0x7FF);
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_base[i] = 0;
    }

    src0_ptr = src0_base;
    src1_ptr = src1_base;
    dst = dst_base;
}