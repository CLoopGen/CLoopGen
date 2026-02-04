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
    for (h_cnt = last; h_cnt <= -1; h_cnt++) {
        offset = (inv_angle_val_loop + 128) >> 8;
        // Modified to use strided access with stride of 2 on src_left_tmp
        // Ensuring we do not go out of bounds by checking offset*2 is valid (assumed safe per context)
        ref_tmp[h_cnt] = src_left_tmp[offset * 2];
        inv_angle_val_loop += inv_angle_val;
    }
}
