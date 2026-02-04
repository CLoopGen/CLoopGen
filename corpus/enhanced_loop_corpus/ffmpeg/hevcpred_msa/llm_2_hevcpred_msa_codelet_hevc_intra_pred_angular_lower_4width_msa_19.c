#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src_top;
extern uint8_t *ref_tmp;
extern int32_t last;
extern int32_t offset;
extern int32_t h_cnt;
extern int32_t inv_angle_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset adjustment
    // Instead of computing a strided-like offset via inv_angle_val, we make access consecutive in ref_tmp
    // by writing from src_top in increasing order starting from a base offset.
    int32_t base_offset = (last * inv_angle_val + 128) >> 8;
    for (h_cnt = last; h_cnt <= -1; h_cnt++) {
        ref_tmp[h_cnt] = src_top[base_offset++];
    }
}
