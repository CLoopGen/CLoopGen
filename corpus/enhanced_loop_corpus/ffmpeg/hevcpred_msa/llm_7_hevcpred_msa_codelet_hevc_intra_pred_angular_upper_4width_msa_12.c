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
    int32_t temp_offset;
    for (h_cnt = last; h_cnt <= -1; h_cnt++) {
        temp_offset = (h_cnt * inv_angle_val + 128) >> 8;
        offset = temp_offset - 1;
        ref_tmp[h_cnt] = src_left[offset];
    }
}
