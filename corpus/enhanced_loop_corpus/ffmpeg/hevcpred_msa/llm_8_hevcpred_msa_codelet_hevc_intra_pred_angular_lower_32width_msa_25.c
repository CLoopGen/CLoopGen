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
for (h_cnt = last; h_cnt <= -1; h_cnt += 2) {
    offset = (h_cnt * inv_angle_val + 128) >> 8;
    ref_tmp[h_cnt] = src_top_tmp[offset];
    if (h_cnt + 1 <= -1) {
        offset = ((h_cnt + 1) * inv_angle_val + 128) >> 8;
        ref_tmp[h_cnt + 1] = src_top_tmp[offset];
    }
}
}
