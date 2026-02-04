#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src_left;
int32_t stride;
uint8_t *tmp_dst;
uint32_t row;
uint8_t inp0;
uint8_t inp1;
uint8_t inp2;
uint8_t inp3;

static uint8_t *internal_src_left;
static uint8_t *internal_tmp_dst;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 MB to target ~0.01 sec runtime

    internal_src_left = (uint8_t*)aligned_alloc(32, data_size);
    internal_tmp_dst = (uint8_t*)aligned_alloc(32, data_size);

    if (!internal_src_left || !internal_tmp_dst) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        internal_src_left[i] = (uint8_t)(i & 0xFF);
        internal_tmp_dst[i] = 0;
    }

    src_left = internal_src_left;
    tmp_dst = internal_tmp_dst;
    stride = 16;
}