#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *ref_tmp;
extern  uint8_t *src_left_tmp;
extern int32_t last;
extern int32_t offset;
extern int32_t h_cnt;
extern int32_t inv_angle_val;
extern int32_t inv_angle_val_loop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (last <= -1) {
        h_cnt = last;
        offset = (inv_angle_val_loop + 128) >> 8;
        ref_tmp[h_cnt] = src_left_tmp[offset];
        inv_angle_val_loop += inv_angle_val;
        h_cnt++;
        for (; h_cnt <= -1; h_cnt++) {
            offset = (inv_angle_val_loop + 128) >> 8;
            ref_tmp[h_cnt] = src_left_tmp[offset];
            inv_angle_val_loop += inv_angle_val;
        }
    }
}
