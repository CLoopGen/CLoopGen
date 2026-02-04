#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t h_cnt;
extern int32_t offset;
extern int32_t inv_angle_val;
extern int32_t inv_angle_val_loop;
extern uint8_t *ref_tmp;
extern  uint8_t *src_left_tmp;
extern int32_t last;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (h_cnt = last; h_cnt <= -3; h_cnt++) {
    int32_t off1 = (inv_angle_val_loop + 128) >> 8;
    inv_angle_val_loop += inv_angle_val;
    int32_t off2 = (inv_angle_val_loop + 128) >> 8;
    inv_angle_val_loop += inv_angle_val;
    int32_t off3 = (inv_angle_val_loop + 128) >> 8;
    inv_angle_val_loop += inv_angle_val;
    int32_t off4 = (inv_angle_val_loop + 128) >> 8;
    inv_angle_val_loop += inv_angle_val;

    ref_tmp[h_cnt]     = src_left_tmp[off1];
    ref_tmp[h_cnt + 1] = src_left_tmp[off2];
    ref_tmp[h_cnt + 2] = src_left_tmp[off3];
    ref_tmp[h_cnt + 3] = src_left_tmp[off4];

    h_cnt += 3;
}
}
