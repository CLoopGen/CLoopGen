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
for (h_cnt = last; h_cnt <= -1 && h_cnt < last + 16; h_cnt++) {
    int32_t temp_offset1 = h_cnt * inv_angle_val;
    int32_t temp_offset2 = temp_offset1 + 64;
    int32_t temp_offset3 = temp_offset1 + 192;
    offset = (temp_offset2 + 128) >> 8;
    ref_tmp[h_cnt] = src_top_tmp[offset];
    if ((h_cnt + 1) <= -1 && h_cnt < last + 15) {
        offset = (temp_offset3 + 128) >> 8;
        ref_tmp[h_cnt + 1] = src_top_tmp[offset];
        h_cnt++;
    }
}
}
