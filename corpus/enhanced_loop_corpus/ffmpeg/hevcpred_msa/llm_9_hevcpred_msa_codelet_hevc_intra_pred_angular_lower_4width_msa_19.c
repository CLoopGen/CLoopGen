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
    int32_t scaled_inv_angle;
    for (h_cnt = last; h_cnt <= -3; h_cnt++) {
        scaled_inv_angle = inv_angle_val << 1;
        offset = -1 + ((h_cnt * scaled_inv_angle + 128) >> 8);
        ref_tmp[h_cnt] = src_top[offset];
        ref_tmp[h_cnt + 1] = src_top[-1 + (((h_cnt + 1) * scaled_inv_angle + 128) >> 8)];
        ref_tmp[h_cnt + 2] = src_top[-1 + (((h_cnt + 2) * scaled_inv_angle + 128) >> 8)];
        h_cnt += 2;
    }
}
