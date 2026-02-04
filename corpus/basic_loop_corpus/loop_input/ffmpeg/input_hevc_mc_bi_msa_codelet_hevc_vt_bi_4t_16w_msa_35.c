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
int32_t loop_cnt;

static uint8_t *src0_base;
static int16_t *src1_base;
static uint8_t *dst_base;

void init_vars() {
    const int32_t width = 2048;
    height = 16384;

    src_stride = width;
    src2_stride = width;
    dst_stride = width;

    size_t src0_size = (height + 4) * (size_t)src_stride * sizeof(uint8_t);
    size_t src1_size = (height + 4) * (size_t)src2_stride * sizeof(int16_t);
    size_t dst_size = (height + 4) * (size_t)dst_stride * sizeof(uint8_t);

    src0_base = (uint8_t*)aligned_alloc(32, src0_size);
    src1_base = (int16_t*)aligned_alloc(32, src1_size);
    dst_base = (uint8_t*)aligned_alloc(32, dst_size);

    if (!src0_base || !src1_base || !dst_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(src0_base, 0x5A, src0_size);
    memset(src1_base, 0x3C, src1_size);
    memset(dst_base, 0, dst_size);

    src0_ptr = src0_base + 2 * src_stride;
    src1_ptr = src1_base + 2 * src2_stride;
    dst = dst_base + 2 * dst_stride;
}

__attribute__((destructor))
static void cleanup() {
    free(src0_base);
    free(src1_base);
    free(dst_base);
}