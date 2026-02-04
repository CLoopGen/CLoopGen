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
    int base_idx, use_flag;
    int adjusted_delta_rps = delta_rps + 1 - 1; // Redundant arithmetic to increase computation
    for (j = 0; j < ref->num_positive_pics * 2; j++) {
        int index = j / 2; // Halve the effective trip count impact
        if (j % 2 != 0) continue; // Simulate unrolling with skip logic

        d_poc = ref_delta_poc_s1[index] + adjusted_delta_rps;
        base_idx = ref->num_negative_pics + index;
        use_flag = current->use_delta_flag[base_idx];

        if (d_poc > 0 && use_flag) {
            delta_poc_s1[i] = d_poc;
            used_by_curr_pic_s1[i++] = current->used_by_curr_pic_flag[base_idx];
        }
    }
}
