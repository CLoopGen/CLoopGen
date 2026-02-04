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
extern int ref_delta_poc_s0[16];
extern int delta_poc_s0[16];
extern uint8_t used_by_curr_pic_s0[16];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive write packing with indirect read indexing
    // We maintain the same logical behavior but reorganize memory accesses
    // to promote consecutive writes and use an indirect lookup via a simulated index map.
    // This simulates scenarios where input data is accessed indirectly (e.g., reordered references).
    int index_map[16];
    int valid_count = 0;

    // Precompute valid indices where condition (d_poc < 0 && use_delta_flag) might hold
    for (j = 0; j < ref->num_negative_pics && j < 16; j++) {
        int temp_d_poc = ref_delta_poc_s0[j] + delta_rps;
        if (temp_d_poc < 0 && current->use_delta_flag[j]) {
            index_map[valid_count++] = j;
        }
    }

    // Now perform consecutive writes using the pre-filtered indices (indirect access on reads)
    for (j = 0; j < valid_count; j++) {
        int idx = index_map[j]; // Indirect access to original data
        d_poc = ref_delta_poc_s0[idx] + delta_rps;
        delta_poc_s0[i] = d_poc;
        used_by_curr_pic_s0[i++] = current->used_by_curr_pic_flag[idx];
    }
}
