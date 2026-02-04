#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct H265RawSTRefPicSet {
    uint8_t inter_ref_pic_set_prediction_flag;
    uint8_t delta_idx_minus1;
    uint8_t delta_rps_sign;
    uint16_t abs_delta_rps_minus1;
    uint8_t used_by_curr_pic_flag[16];
    uint8_t use_delta_flag[16];
    uint8_t num_negative_pics;
    uint8_t num_positive_pics;
    uint16_t delta_poc_s0_minus1[16];
    uint8_t used_by_curr_pic_s0_flag[16];
    uint16_t delta_poc_s1_minus1[16];
    uint8_t used_by_curr_pic_s1_flag[16];
} H265RawSTRefPicSet;

extern H265RawSTRefPicSet *current;
extern int i;
extern int j;
extern  H265RawSTRefPicSet *ref;
extern int delta_rps;
extern int d_poc;
extern int ref_delta_poc_s1[16];
extern int delta_poc_s1[16];
extern uint8_t used_by_curr_pic_s1[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with reverse iteration and stride of 2 (simulating cache-aware access)
    int start = (ref->num_positive_pics - 1) | 1; // Round down to nearest odd number if needed
    int base_offset = ref->num_negative_pics;
    
    for (j = start; j >= 0; j -= 2) {  // Reverse, strided access (step of -2)
        if (j >= ref->num_positive_pics) continue; // Skip out-of-bound initial index due to rounding
        d_poc = ref_delta_poc_s1[j] + delta_rps;
        int idx = base_offset + j;
        if (d_poc > 0 && current->use_delta_flag[idx]) {
            delta_poc_s1[i] = d_poc;
            used_by_curr_pic_s1[i++] = current->used_by_curr_pic_flag[idx];
        }
    }
    // Handle the last element if num_positive_pics was even and we skipped j=1
    if (ref->num_positive_pics > 0 && (ref->num_positive_pics % 2) == 0) {
        j = 1;
        d_poc = ref_delta_poc_s1[j] + delta_rps;
        int idx = base_offset + j;
        if (d_poc > 0 && current->use_delta_flag[idx]) {
            delta_poc_s1[i] = d_poc;
            used_by_curr_pic_s1[i++] = current->used_by_curr_pic_flag[idx];
        }
    }
}
