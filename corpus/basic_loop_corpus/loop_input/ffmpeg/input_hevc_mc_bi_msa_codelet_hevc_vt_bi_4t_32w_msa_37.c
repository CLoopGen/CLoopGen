#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024)

uint8_t *src0_ptr;
int32_t src_stride;
int16_t *src1_ptr;
int32_t src2_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;
uint8_t *dst_tmp;

static uint8_t *src0_base;
static int16_t *src1_base;
static uint8_t *dst_base;
static uint8_t *dst_tmp_base;

void init_vars() {
    const int element_size = 16;
    height = (int32_t)((TOTAL_ELEMENTS / element_size) / 2);
    src_stride = 16;
    src2_stride = 8;
    dst_stride = 16;

    size_t src0_size = (size_t)(height * 2 * src_stride);
    size_t src1_size = (size_t)(height * 2 * src2_stride);
    size_t dst_size = (size_t)(height * 2 * dst_stride);
    size_t dst_tmp_size = (size_t)(height * 2 * dst_stride);

    src0_base = (uint8_t *)aligned_alloc(32, src0_size);
    src1_base = (int16_t *)aligned_alloc(32, src1_size * sizeof(int16_t));
    dst_base = (uint8_t *)aligned_alloc(32, dst_size);
    dst_tmp_base = (uint8_t *)aligned_alloc(32, dst_tmp_size);

    if (!src0_base || !src1_base || !dst_base || !dst_tmp_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src0_size; ++i) {
        src0_base[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < src1_size * sizeof(int16_t); ++i) {
        ((uint8_t *)src1_base)[i] = (uint8_t)(i & 0xFF);
    }
    memset(dst_base, 0, dst_size);
    memset(dst_tmp_base, 0, dst_tmp_size);

    src0_ptr = src0_base;
    src1_ptr = src1_base;
    dst = dst_base;
    dst_tmp = dst_tmp_base;

    loop_cnt = (uint32_t)height;
}