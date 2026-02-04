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
// Use indirect memory access via precomputed index array (simulated using offset variations)
int32_t temp_index;
for (h_cnt = last; h_cnt <= -1; h_cnt++) {
    offset = (inv_angle_val_loop + 128) >> 8;
    temp_index = offset ^ 1;  // Simple bit manipulation for indirect-like access
    ref_tmp[h_cnt] = src_left_tmp[temp_index];
    inv_angle_val_loop += inv_angle_val ^ 0x03;  // Slight perturbation to create non-linear progression
}
}
