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
    for (h_cnt = last; h_cnt <= -1 && inv_angle_val != 0; h_cnt++) {
        offset = -1 + ((h_cnt * inv_angle_val + 128) >> 8);
        ref_tmp[h_cnt] = src_left[offset];
        if (offset < 0) break;
    }
}
