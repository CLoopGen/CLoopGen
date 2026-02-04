#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t src_stride = 16;
int32_t dst_stride = 32;
int32_t height = 1000000;
uint32_t loop_cnt;

uint8_t *src_tmp;
int16_t *dst_tmp;

void init_vars() {
    size_t src_size = (size_t)(height + 1) * src_stride;
    size_t dst_size = (size_t)(height + 1) * dst_stride;

    src_tmp = (uint8_t*)aligned_alloc(32, src_size);
    dst_tmp = (int16_t*)aligned_alloc(32, dst_size);

    if (!src_tmp || !dst_tmp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src_tmp[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < dst_size / sizeof(int16_t); i++) {
        dst_tmp[i] = (int16_t)(i & 0xFFFF);
    }
}