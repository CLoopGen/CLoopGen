#include <stdint.h>
#include <stdlib.h>

uint8_t *ref_tmp;
uint8_t *src_top_tmp;
int32_t last;
int32_t offset;
int32_t h_cnt;
int32_t inv_angle_val;

void init_vars() {
    const size_t data_size = 16777216; // 16 MB for ~0.01 sec runtime

    ref_tmp = (uint8_t*)aligned_alloc(32, data_size);
    src_top_tmp = (uint8_t*)aligned_alloc(32, data_size);

    if (!ref_tmp || !src_top_tmp) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        src_top_tmp[i] = (uint8_t)(i & 0xFF);
        ref_tmp[i] = 0;
    }

    last = 0;
    inv_angle_val = 256;
}

void loop(); 

__attribute__((constructor))
void auto_init() {
    init_vars();
}