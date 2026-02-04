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
    int32_t local_offset, prev_offset = 0;
    for (h_cnt = last; h_cnt <= -1; h_cnt++) {
        local_offset = -1 + ((h_cnt * inv_angle_val + 128) >> 8);
        if (h_cnt > last) {
            ref_tmp[h_cnt - 1] = src_left[prev_offset]; // Introduce WAW and WAR dependency via delayed write
        }
        prev_offset = local_offset;
    }
    // Handle last iteration separately to maintain semantic consistency
    if (last <= -1) {
        ref_tmp[-1] = src_left[-1 + (((-1) * inv_angle_val + 128) >> 8)];
    }
}
