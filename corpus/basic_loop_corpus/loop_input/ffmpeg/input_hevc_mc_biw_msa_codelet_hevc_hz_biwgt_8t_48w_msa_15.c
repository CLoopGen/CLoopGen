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
uint32_t loop_cnt;

static uint8_t *src0_base;
static int16_t *src1_base;
static uint8_t *dst_base;

void init_vars() {
    const uint32_t total_iterations = 64;
    const size_t data_size = 16 * 1024 * 1024; // 16 MB per buffer

    src_stride = 256;
    src2_stride = 512;
    dst_stride = 128;

    src0_base = aligned_alloc(64, data_size);
    src1_base = aligned_alloc(64, data_size * sizeof(int16_t));
    dst_base = aligned_alloc(64, data_size);

    if (!src0_base || !src1_base || !dst_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(src0_base, 0x5A, data_size);
    for (size_t i = 0; i < data_size / sizeof(int16_t); ++i) {
        src1_base[i] = (int16_t)(i & 0xFFFF);
    }
    memset(dst_base, 0, data_size);

    src0_ptr = src0_base;
    src1_ptr = src1_base;
    dst = dst_base;

    loop_cnt = 64;
}

__attribute__((destructor))
static void cleanup() {
    free(src0_base);
    free(src1_base);
    free(dst_base);
}