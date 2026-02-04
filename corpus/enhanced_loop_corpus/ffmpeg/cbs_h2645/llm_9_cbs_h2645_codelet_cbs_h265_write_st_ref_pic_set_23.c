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



void loop(){
    for (j = 0; j < (ref->num_negative_pics > 8 ? 8 : ref->num_negative_pics); j += 2) {
        int temp_d_poc1 = ref_delta_poc_s0[j] + delta_rps;
        int temp_val1 = (temp_d_poc1 < 0 && current->use_delta_flag[j]) ? 1 : 0;
        if (temp_val1) {
            delta_poc_s0[i] = temp_d_poc1;
            used_by_curr_pic_s0[i++] = current->used_by_curr_pic_flag[j];
        }
        if (j + 1 < ref->num_negative_pics) {
            int temp_d_poc2 = ref_delta_poc_s0[j+1] + delta_rps;
            int temp_val2 = (temp_d_poc2 < 0 && current->use_delta_flag[j+1]) ? 1 : 0;
            if (temp_val2) {
                delta_poc_s0[i] = temp_d_poc2;
                used_by_curr_pic_s0[i++] = current->used_by_curr_pic_flag[j+1];
            }
        }
    }
}
