#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *ref_tmp;
extern  uint8_t *src_top_tmp;
extern int32_t last;
extern int32_t offset;
extern int32_t h_cnt;
extern int32_t inv_angle_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp_offset1, temp_offset2;
    for (h_cnt = last; h_cnt <= -2; h_cnt += 2) {
        temp_offset1 = (h_cnt * inv_angle_val + 128) >> 8;
        temp_offset2 = ((h_cnt + 1) * inv_angle_val + 128) >> 8;
        ref_tmp[h_cnt] = src_top_tmp[temp_offset1];
        ref_tmp[h_cnt + 1] = src_top_tmp[temp_offset2];
    }
    if (h_cnt == -1) {
        offset = (-1 * inv_angle_val + 128) >> 8;
        ref_tmp[-1] = src_top_tmp[offset];
    }
}
