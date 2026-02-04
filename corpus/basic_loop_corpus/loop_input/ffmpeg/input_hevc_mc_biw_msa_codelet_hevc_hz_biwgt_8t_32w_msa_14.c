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

static uint8_t *src0_base;
static int16_t *src1_base;
static uint8_t *dst_base;

void init_vars() {
    height = 1 << 18; // Approximately 256K iterations to target ~0.01s runtime on modern CPU
    src_stride = 1;
    src2_stride = 2;
    dst_stride = 4;

    size_t src0_size = (size_t)height * abs(src_stride);
    size_t src1_size = (size_t)height * abs(src2_stride);
    size_t dst_size = (size_t)height * abs(dst_stride);

    src0_base = aligned_alloc(64, src0_size);
    src1_base = aligned_alloc(64, src1_size * sizeof(int16_t));
    dst_base = aligned_alloc(64, dst_size);

    for (size_t i = 0; i < src0_size; i++) {
        src0_base[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < src1_size; i++) {
        src1_base[i] = (int16_t)(i & 0xFFFF);
    }

    src0_ptr = src0_base;
    src1_ptr = src1_base;
    dst = dst_base;
}