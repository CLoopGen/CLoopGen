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
    const uint32_t data_size_mb = 64;
    const uint32_t total_elements = data_size_mb * (1 << 20);
    
    height = 8192;
    
    src_stride = 2048;
    src2_stride = 1024;
    dst_stride = 2048;

    src0_base = aligned_alloc(32, total_elements * sizeof(uint8_t));
    src1_base = aligned_alloc(32, total_elements * sizeof(int16_t));
    dst_base = aligned_alloc(32, total_elements * sizeof(uint8_t));

    if (!src0_base || !src1_base || !dst_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_elements; ++i) {
        src0_base[i] = (uint8_t)(i & 0xFF);
        src1_base[i] = (int16_t)(i & 0x7FF);
        dst_base[i] = 0;
    }

    src0_ptr = src0_base;
    src1_ptr = src1_base;
    dst = dst_base;
}