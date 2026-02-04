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
    int32_t indices[256];
    for (int i = 0, h = last; h <= -1; h++, i++) {
        indices[i] = -1 + ((h * inv_angle_val + 128) >> 8);
    }
    for (int i = 0, h = last; h <= -1; h++, i++) {
        ref_tmp[h] = src_left[indices[i]];
    }
}
