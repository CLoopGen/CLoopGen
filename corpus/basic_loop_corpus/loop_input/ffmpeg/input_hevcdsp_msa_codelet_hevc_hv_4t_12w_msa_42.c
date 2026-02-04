#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t src_stride = 256;
int32_t dst_stride = 128;
uint32_t loop_cnt;

uint8_t *src_tmp;
int16_t *dst_tmp;

static uint8_t *src_base;
static int16_t *dst_base;
static size_t total_src_size;
static size_t total_dst_size;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec estimate

    total_src_size = data_size;
    total_dst_size = data_size / 2; // Since dst is int16_t, twice the element size

    src_base = (uint8_t*)aligned_alloc(32, total_src_size);
    dst_base = (int16_t*)aligned_alloc(32, total_dst_size);

    if (!src_base || !dst_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_src_size; i++) {
        src_base[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < total_dst_size / sizeof(int16_t); i++) {
        dst_base[i] = (int16_t)(i & 0xFFFF);
    }

    src_tmp = src_base;
    dst_tmp = dst_base;
}