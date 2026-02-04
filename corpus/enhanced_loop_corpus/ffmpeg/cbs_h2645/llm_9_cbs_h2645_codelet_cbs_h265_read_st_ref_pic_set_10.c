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
extern int delta_poc_s0[16];
extern uint8_t used_by_curr_pic_s0[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = ref->num_positive_pics;
    for (j = 0; j < limit; j++) {
        int idx = ref->num_positive_pics - 1 - j;
        int temp_d_poc = ref_delta_poc_s1[idx] + delta_rps;
        int offset = ref->num_negative_pics + idx;
        if (temp_d_poc < 0) {
            uint8_t use_flag = current->use_delta_flag[offset];
            if (use_flag) {
                int curr_index = i;
                delta_poc_s0[curr_index] = temp_d_poc;
                used_by_curr_pic_s0[curr_index] = current->used_by_curr_pic_flag[offset];
                i = curr_index + 1;
            }
        }
    }
}
