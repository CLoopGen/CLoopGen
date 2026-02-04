#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *ref;
int32_t ref_stride;
int32_t height;
int32_t ht_cnt;

static uint8_t *src_data;
static uint8_t *ref_data;

void init_vars() {
    const int32_t block_height = 1024;
    const int32_t block_width = 1024;
    src_stride = block_width;
    ref_stride = block_width;
    height = block_height;

    size_t src_size = (size_t)block_height * src_stride;
    size_t ref_size = (size_t)block_height * ref_stride;

    src_data = aligned_alloc(32, src_size);
    ref_data = aligned_alloc(32, ref_size);

    src = src_data;
    ref = ref_data;

    for (size_t i = 0; i < src_size; ++i) {
        src_data[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < ref_size; ++i) {
        ref_data[i] = (uint8_t)((i + 33) & 0xFF);
    }

    ht_cnt = height >> 2;
}