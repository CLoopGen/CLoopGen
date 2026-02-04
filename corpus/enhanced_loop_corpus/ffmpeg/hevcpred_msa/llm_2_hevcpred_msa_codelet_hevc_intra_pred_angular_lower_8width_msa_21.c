#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *ref_tmp;
extern  uint8_t *src_top_tmp;
extern int32_t last;
extern int32_t offset;
extern int32_t h_cnt;
extern int32_t inv_angle_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration and offset accumulation
    int32_t temp_offset = (last * inv_angle_val + 128) >> 8;
    for (h_cnt = last; h_cnt <= -1; h_cnt++) {
        ref_tmp[-h_cnt] = src_top_tmp[temp_offset];  // Reversed write index for consecutive ref_tmp access
        temp_offset += inv_angle_val >> 8;  // Increment offset linearly to promote predictability
    }
}
