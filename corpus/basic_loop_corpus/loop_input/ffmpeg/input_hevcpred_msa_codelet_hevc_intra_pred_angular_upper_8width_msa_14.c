#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *ref_tmp;
uint8_t *src_left_tmp;
int32_t last;
int32_t offset;
int32_t h_cnt;
int32_t inv_angle_val;
int32_t inv_angle_val_loop;

void init_vars() {
    const size_t data_size = 134217728; // 128 MB to target ~0.01 sec runtime

    ref_tmp = (uint8_t*)aligned_alloc(32, data_size);
    src_left_tmp = (uint8_t*)aligned_alloc(32, data_size);

    if (!ref_tmp || !src_left_tmp) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        src_left_tmp[i] = (uint8_t)(i & 0xFF);
        ref_tmp[i] = 0;
    }

    last = 0;
    h_cnt = last;
    inv_angle_val = 256;
    inv_angle_val_loop = -256;
}

// Note: The loop function is defined externally and will be linked in.