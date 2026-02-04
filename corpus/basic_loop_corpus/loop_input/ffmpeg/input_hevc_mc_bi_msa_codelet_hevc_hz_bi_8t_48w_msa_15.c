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
static size_t total_data_size = 64 * 1024 * 1024; // ~64 MB for workload balance

void init_vars() {
    // Allocate large buffers to ensure meaningful runtime (~64MB each)
    src0_base = aligned_alloc(32, total_data_size);
    src1_base = aligned_alloc(32, total_data_size);
    dst_base = aligned_alloc(32, total_data_size);

    // Initialize pointers
    src0_ptr = src0_base;
    src1_ptr = src1_base;
    dst = dst_base;

    // Set strides (simulate moderate step over rows of a matrix or struct array)
    src_stride = 1024;
    src2_stride = 512;
    dst_stride = 1024;

    // Ensure that with 64 iterations, we don't go out of bounds
    // Max offset: 63 * max(stride) < total_data_size
    // 63 * 1024 ~ 64KB, so 64MB is more than sufficient
}

// Cleanup function to avoid memory leaks (not required but good practice)
void free_vars() {
    free(src0_base);
    free(src1_base);
    free(dst_base);
}