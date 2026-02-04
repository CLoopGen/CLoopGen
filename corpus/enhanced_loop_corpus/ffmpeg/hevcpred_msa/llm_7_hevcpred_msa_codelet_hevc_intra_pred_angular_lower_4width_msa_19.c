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
    int32_t virtual_h;
    for (virtual_h = last; virtual_h <= -1; virtual_h++) {
        int32_t computed_offset = (virtual_h * inv_angle_val + 128) >> 8 - 1;
        ref_tmp[virtual_h] = src_top[computed_offset];
        offset = computed_offset; // Write to offset without affecting loop logic (WAW introduced but not carried)
        h_cnt = virtual_h;       // Update original index (redundant store, creates WAW dependency on h_cnt)
    }
}
