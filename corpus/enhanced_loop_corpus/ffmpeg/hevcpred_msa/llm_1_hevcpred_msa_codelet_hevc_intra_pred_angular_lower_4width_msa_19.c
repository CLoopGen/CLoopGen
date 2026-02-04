#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src_top;
extern uint8_t *ref_tmp;
extern int32_t last;
extern int32_t offset;
extern int32_t h_cnt;
extern int32_t inv_angle_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (last <= -1) {
        h_cnt = last;
        offset = -1 + ((h_cnt * inv_angle_val + 128) >> 8);
        ref_tmp[h_cnt] = src_top[offset];
    }
}
