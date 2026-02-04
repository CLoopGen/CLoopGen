#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (128 * 1024 * 1024) // ~128MB for sufficient runtime (~0.01s on modern CPU)

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
    const int alignment = 64;
    height = 16384; // Sufficient iterations to reach target time

    src_stride = 16;
    src2_stride = 8;
    dst_stride = 32;

    size_t src0_size = (size_t)(height * abs(src_stride)) + alignment;
    size_t src1_size = (size_t)(height * abs(src2_stride)) + alignment;
    size_t dst_size = (size_t)(height * abs(dst_stride)) + alignment;

    posix_memalign((void**)&src0_base, alignment, src0_size);
    posix_memalign((void**)&src1_base, alignment, src1_size);
    posix_memalign((void**)&dst_base, alignment, dst_size);

    memset(src0_base, 0x55, src0_size);
    memset(src1_base, 0xAA, src1_size);
    memset(dst_base, 0x00, dst_size);

    src0_ptr = src0_base;
    src1_ptr = src1_base;
    dst = dst_base;
}

// Cleanup function to avoid memory leaks (not called here but implied usage)
// Free in calling context if needed: free(src0_base); free(src1_base); free(dst_base);