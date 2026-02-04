#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t h_cnt;
extern int32_t inv_angle_val;
extern int32_t offset;
extern uint8_t *ref_tmp;
extern  uint8_t *src_top_tmp;
extern int32_t last;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp_offset1, temp_offset2;
    for (h_cnt = last; h_cnt <= -3; h_cnt += 2) {
        temp_offset1 = (h_cnt * inv_angle_val + 128) >> 8;
        temp_offset2 = ((h_cnt + 1) * inv_angle_val + 128) >> 8;
        ref_tmp[h_cnt] = src_top_tmp[temp_offset1];
        ref_tmp[h_cnt + 1] = src_top_tmp[temp_offset2];
    }
    // Handle any remaining element if the range is odd-sized
    if (h_cnt == -1) {
        offset = (h_cnt * inv_angle_val + 128) >> 8;
        ref_tmp[h_cnt] = src_top_tmp[offset];
    }
}
