#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src_left;
uint8_t *ref_tmp;
int32_t last;
int32_t h_cnt;
int32_t inv_angle_val;
int32_t offset;

static uint8_t *src_left_buffer;
static uint8_t *ref_tmp_buffer;
static size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime

void init_vars() {
    src_left_buffer = (uint8_t*)aligned_alloc(32, data_size);
    ref_tmp_buffer = (uint8_t*)aligned_alloc(32, data_size);

    if (!src_left_buffer || !ref_tmp_buffer) {
        exit(1);
    }

    src_left = src_left_buffer;
    ref_tmp = ref_tmp_buffer;

    for (size_t i = 0; i < data_size; i++) {
        src_left_buffer[i] = (uint8_t)(i & 0xFF);
        ref_tmp_buffer[i] = 0;
    }

    inv_angle_val = 256;
    last = 0;
    h_cnt = 0;
}