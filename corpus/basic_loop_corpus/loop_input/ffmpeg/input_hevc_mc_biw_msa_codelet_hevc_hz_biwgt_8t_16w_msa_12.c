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
static size_t total_size;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 MB for sufficient runtime (~0.01s on modern CPU)

    total_size = data_size;

    src_stride = 64;
    src2_stride = 32;
    dst_stride = 64;

    height = (data_size / src_stride) & ~1; // Ensure divisible by 2 for loop unroll

    src0_base = aligned_alloc(64, data_size);
    src1_base = aligned_alloc(64, data_size);
    dst_base = aligned_alloc(64, data_size);

    if (!src0_base || !src1_base || !dst_base) {
        exit(1);
    }

    src0_ptr = src0_base;
    src1_ptr = src1_base;
    dst = dst_base;

    for (size_t i = 0; i < data_size; i++) {
        src0_base[i] = (uint8_t)(i & 0xFF);
        dst_base[i] = 0;
    }
    for (size_t i = 0; i < data_size / sizeof(int16_t); i++) {
        src1_base[i] = (int16_t)(i & 0xFFFF);
    }
}