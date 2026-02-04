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
    int32_t local_accum = inv_angle_val_loop; // Remove direct loop-carried RAW on inv_angle_val_loop
    for (h_cnt = last; h_cnt <= -1; h_cnt++) {
        offset = (local_accum + 128) >> 8;
        ref_tmp[h_cnt] = src_left_tmp[offset];
        local_accum += inv_angle_val; // Update local copy instead
    }
    inv_angle_val_loop = local_accum; // Write back once after loop (eliminates loop-carried WAW)
}
