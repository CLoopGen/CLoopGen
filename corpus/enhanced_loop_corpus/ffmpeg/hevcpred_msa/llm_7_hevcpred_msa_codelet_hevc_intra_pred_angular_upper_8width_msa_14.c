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
    int32_t accumulated_angle = inv_angle_val_loop;
    for (h_cnt = last; h_cnt <= -1; h_cnt++) {
        int32_t offset = (accumulated_angle + 128) >> 8;
        ref_tmp[h_cnt] = src_left_tmp[offset];
        accumulated_angle += inv_angle_val;
    }
    inv_angle_val_loop = accumulated_angle;
}
