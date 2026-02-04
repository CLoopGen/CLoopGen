#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src_left;
extern uint8_t *ref_tmp;
extern int32_t last;
extern int32_t h_cnt;
extern int32_t inv_angle_val;
extern int32_t offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp_offset1, temp_offset2;
    for (h_cnt = last; h_cnt <= -2; h_cnt++) {
        temp_offset1 = h_cnt * inv_angle_val;
        temp_offset2 = (h_cnt + 1) * inv_angle_val;
        offset = -1 + ((temp_offset1 + 128) >> 8);
        ref_tmp[h_cnt] = src_left[offset];
        offset = -1 + ((temp_offset2 + 128) >> 8);
        ref_tmp[h_cnt + 1] = src_left[offset];
        h_cnt++;
    }
    if (h_cnt == -1) {
        offset = -1 + ((h_cnt * inv_angle_val + 128) >> 8);
        ref_tmp[h_cnt] = src_left[offset];
    }
}
