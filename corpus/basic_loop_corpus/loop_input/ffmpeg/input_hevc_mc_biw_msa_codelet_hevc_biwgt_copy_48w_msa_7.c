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
uint32_t loop_cnt;

static uint8_t *src0_base;
static int16_t *src1_base;
static uint8_t *dst_base;

void init_vars() {
    const size_t data_size = 16 << 20; // 16 MB of data per buffer
    const size_t num_elements = data_size / sizeof(uint8_t);
    src_stride = 1024;
    src2_stride = 512;
    dst_stride = 1024;

    src0_base = aligned_alloc(32, data_size + src_stride * 64);
    src1_base = aligned_alloc(32, data_size + src2_stride * 64);
    dst_base = aligned_alloc(32, data_size + dst_stride * 64);

    if (!src0_base || !src1_base || !dst_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        src0_base[i] = (uint8_t)(i & 0xFF);
        dst_base[i] = 0;
    }
    for (size_t i = 0; i < data_size / sizeof(int16_t); i++) {
        src1_base[i] = (int16_t)(i & 0xFFFF);
    }

    src0_ptr = src0_base;
    src1_ptr = src1_base;
    dst = dst_base;
    loop_cnt = 64;
}