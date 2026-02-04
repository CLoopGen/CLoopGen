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
    for (h_cnt = last; h_cnt <= -1 && inv_angle_val != 0; h_cnt++) {
        offset = (h_cnt * inv_angle_val + 128) >> 8;
        ref_tmp[h_cnt] = src_top_tmp[offset];
        if (offset < 0) break;
    }
}
