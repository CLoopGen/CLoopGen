#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (128 * 1024 * 1024)

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
    height = 1024; 

    src_stride = 2048;
    src2_stride = 2048;
    dst_stride = 2048;

    size_t src0_size = (size_t)(height * src_stride) * sizeof(uint8_t);
    size_t src1_size = (size_t)(height * src2_stride) * sizeof(int16_t);
    size_t dst_size = (size_t)(height * dst_stride) * sizeof(uint8_t);

    posix_memalign((void**)&src0_base, alignment, src0_size);
    posix_memalign((void**)&src1_base, alignment, src1_size);
    posix_memalign((void**)&dst_base, alignment, dst_size);

    memset(src0_base, 0x55, src0_size);
    memset(src1_base, 0xAA, src1_size);
    memset(dst_base, 0x00, dst_size);

    src0_ptr = src0_base;
    src1_ptr = src1_base;
    dst = dst_base;

    loop_cnt = 0;
}