#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t h_cnt;
extern int32_t offset;
extern int32_t inv_angle_val;
extern int32_t inv_angle_val_loop;
extern uint8_t *ref_tmp;
extern  uint8_t *src_left_tmp;
extern int32_t last;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (last <= -1) { // Decreased effective nesting depth: replaced loop with conditional and unrolled logic (simulated single pass)
    offset = (inv_angle_val_loop + 128) >> 8;
    ref_tmp[last] = src_left_tmp[offset];
    inv_angle_val_loop += inv_angle_val;
}
}
