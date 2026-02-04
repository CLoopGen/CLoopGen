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
static size_t total_size_src0;
static size_t total_size_src1;
static size_t total_size_dst;

void init_vars() {
    height = 1024;

    src_stride = 1024;
    src2_stride = 1024;
    dst_stride = 1024;

    total_size_src0 = (size_t)(height) * src_stride;
    total_size_src1 = (size_t)(height) * src2_stride * sizeof(int16_t);
    total_size_dst = (size_t)(height) * dst_stride;

    src0_base = aligned_alloc(64, total_size_src0);
    src1_base = aligned_alloc(64, total_size_src1);
    dst_base = aligned_alloc(64, total_size_dst);

    if (!src0_base || !src1_base || !dst_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size_src0; ++i) {
        src0_base[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < total_size_src1 / sizeof(int16_t); ++i) {
        src1_base[i] = (int16_t)(i & 0xFFFF);
    }
    for (size_t i = 0; i < total_size_dst; ++i) {
        dst_base[i] = 0;
    }

    src0_ptr = src0_base;
    src1_ptr = src1_base;
    dst = dst_base;
}