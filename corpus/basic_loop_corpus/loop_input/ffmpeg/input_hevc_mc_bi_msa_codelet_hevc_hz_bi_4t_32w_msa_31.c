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
    const size_t total_data_size = 64 * 1024 * 1024; // ~64MB total to target ~0.01s runtime

    // Estimate approximate data per iteration
    // Assume moderate strides and sufficient height for warm cache behavior
    height = 16384; // 16K iterations typical for measurable time

    // Use moderate strides to simulate realistic image/row processing
    src_stride = 4096;
    src2_stride = 2048;
    dst_stride = 4096;

    // Allocate large contiguous blocks to ensure no overflow over height steps
    src0_base = (uint8_t*)aligned_alloc(64, total_data_size);
    src1_base = (int16_t*)aligned_alloc(64, total_data_size);
    dst_base = (uint8_t*)aligned_alloc(64, total_data_size);

    if (!src0_base || !src1_base || !dst_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize pointers to start of allocated regions
    src0_ptr = src0_base;
    src1_ptr = src1_base;
    dst = dst_base;

    // Ensure all memory is touched to prevent lazy allocation issues
    memset(src0_base, 0x5A, total_data_size);
    memset(src1_base, 0x3C, total_data_size);
    memset(dst_base, 0, total_data_size);
}