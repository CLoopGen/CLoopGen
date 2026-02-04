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
    // Variant 2: Strided memory access on source array with increased stride
    int32_t stride = (inv_angle_val >> 7) + 1;  // Create a small positive stride
    int32_t base_offset = (last * inv_angle_val + 128) >> 8;
    for (h_cnt = last; h_cnt <= -1; h_cnt++) {
        int32_t effective_offset = base_offset + h_cnt * stride;  // Strided access pattern
        ref_tmp[h_cnt] = src_top_tmp[effective_offset & 0xFF];  // Bound check via masking for realism
    }
}
