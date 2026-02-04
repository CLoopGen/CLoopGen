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

static uint8_t *src_buffer;
static uint8_t *ref_buffer;

void init_vars() {
    const int32_t block_height = 1024;
    const int32_t block_width = 1024;
    src_stride = block_width;
    ref_stride = block_width;
    height = block_height;

    size_t src_size = (size_t)block_height * src_stride;
    size_t ref_size = (size_t)block_height * ref_stride;

    src_buffer = (uint8_t*)aligned_alloc(64, src_size);
    ref_buffer = (uint8_t*)aligned_alloc(64, ref_size);

    if (!src_buffer || !ref_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < ref_size; ++i) {
        ref_buffer[i] = (uint8_t)((i * 3) & 0xFF);
    }

    src = src_buffer;
    ref = ref_buffer;
}