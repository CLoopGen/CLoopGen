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
    // Variant 2: Strided memory access on src_top with fixed stride
    // Replace the angle-based dynamic offset with a constant stride access pattern
    // This creates a regular but non-unit stride through src_top, while still filling ref_tmp consecutively
    int32_t stride = (inv_angle_val + 128) >> 8; // Collapse angle to effective step
    int32_t current = (last * inv_angle_val + 128) >> 8;
    for (h_cnt = last; h_cnt <= -1; h_cnt++) {
        ref_tmp[h_cnt] = src_top[current];
        current += stride; // Strided traversal in source
    }
}
