#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024)

uint8_t *src0_ptr;
int32_t src_stride;
int16_t *src1_ptr;
int32_t src2_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;

static uint8_t src0_data[TOTAL_ELEMENTS];
static int16_t src1_data[TOTAL_ELEMENTS / sizeof(int16_t)];
static uint8_t dst_data[TOTAL_ELEMENTS];

void init_vars() {
    const int element_size_log2 = 4; 
    const int block_height = 4;
    
    src_stride = (1 << element_size_log2);
    src2_stride = (1 << element_size_log2);
    dst_stride = (1 << element_size_log2);

    height = (TOTAL_ELEMENTS / src_stride) & ~3; 

    src0_ptr = src0_data;
    src1_ptr = src1_data;
    dst = dst_data;

    loop_cnt = 0;

    memset(src0_data, 0x55, TOTAL_ELEMENTS);
    memset(src1_data, 0xAA, TOTAL_ELEMENTS / sizeof(int16_t) * sizeof(int16_t));
    memset(dst_data, 0x00, TOTAL_ELEMENTS);
}