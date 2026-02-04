#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE_MB 64
#define TOTAL_BYTES (DATA_SIZE_MB * 1024ULL * 1024ULL)

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
    const size_t element_size_src0 = sizeof(uint8_t);
    const size_t element_size_src1 = sizeof(int16_t);
    const size_t element_size_dst = sizeof(uint8_t);

    const int32_t rows = 1 << 16;
    const int32_t cols = 256;

    src_stride = cols;
    src2_stride = cols;
    dst_stride = cols;
    height = rows;

    const size_t src0_pitch = src_stride * sizeof(uint8_t);
    const size_t src1_pitch = src2_stride * sizeof(int16_t);
    const size_t dst_pitch = dst_stride * sizeof(uint8_t);

    const size_t src0_total = rows * src0_pitch;
    const size_t src1_total = rows * src1_pitch;
    const size_t dst_total = rows * dst_pitch;

    src0_base = aligned_alloc(64, src0_total);
    src1_base = aligned_alloc(64, src1_total);
    dst_base = aligned_alloc(64, dst_total);

    if (!src0_base || !src1_base || !dst_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src0_total; ++i) {
        src0_base[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < src1_total / sizeof(int16_t); ++i) {
        src1_base[i] = (int16_t)(i & 0x7FF);
    }
    for (size_t i = 0; i < dst_total; ++i) {
        dst_base[i] = 0;
    }

    src0_ptr = src0_base;
    src1_ptr = src1_base;
    dst = dst_base;
}