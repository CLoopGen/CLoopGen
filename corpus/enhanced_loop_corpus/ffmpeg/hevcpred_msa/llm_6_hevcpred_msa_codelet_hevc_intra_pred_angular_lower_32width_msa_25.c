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
    int32_t temp_offset;
    uint8_t temp_value;
    for (h_cnt = last; h_cnt <= -1; h_cnt++) {
        temp_offset = (h_cnt * inv_angle_val + 128) >> 8;
        temp_value = src_top_tmp[temp_offset];
        ref_tmp[h_cnt] = temp_value;
    }
}
