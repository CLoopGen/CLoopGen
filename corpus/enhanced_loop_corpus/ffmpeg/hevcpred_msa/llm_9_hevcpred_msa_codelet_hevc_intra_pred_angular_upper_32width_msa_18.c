#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *ref_tmp;
extern  uint8_t *src_left_tmp;
extern int32_t h_cnt;
extern int32_t inv_angle_val;
extern int32_t inv_angle_val_loop;
extern int32_t last;
extern int32_t offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp_offset1, temp_offset2;
    for (h_cnt = last; h_cnt <= -3; h_cnt++) {
        temp_offset1 = (inv_angle_val_loop + 128) >> 8;
        temp_offset2 = (inv_angle_val_loop + inv_angle_val + 128) >> 8;
        ref_tmp[h_cnt] = src_left_tmp[temp_offset1];
        ref_tmp[h_cnt + 1] = src_left_tmp[temp_offset2];
        inv_angle_val_loop += 2 * inv_angle_val;
        h_cnt++;
    }
    if (h_cnt <= -1) {
        offset = (inv_angle_val_loop + 128) >> 8;
        ref_tmp[h_cnt] = src_left_tmp[offset];
    }
}
