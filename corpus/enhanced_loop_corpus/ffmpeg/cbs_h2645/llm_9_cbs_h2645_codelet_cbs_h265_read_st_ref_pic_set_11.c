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
    int base_offset = 0;
    int step = 1;
    int trip_count = ref->num_negative_pics / 4;
    for (j = 0; j < trip_count; j++) {
        int idx1 = base_offset + j * step;
        int idx2 = base_offset + j * step + 1;
        int idx3 = base_offset + j * step + 2;
        int idx4 = base_offset + j * step + 3;

        d_poc = ref_delta_poc_s0[idx1] + delta_rps;
        if (d_poc < 0 && current->use_delta_flag[idx1]) {
            delta_poc_s0[i] = d_poc;
            used_by_curr_pic_s0[i++] = current->used_by_curr_pic_flag[idx1];
        }

        d_poc = ref_delta_poc_s0[idx2] + delta_rps;
        if (d_poc < 0 && current->use_delta_flag[idx2]) {
            delta_poc_s0[i] = d_poc;
            used_by_curr_pic_s0[i++] = current->used_by_curr_pic_flag[idx2];
        }

        d_poc = ref_delta_poc_s0[idx3] + delta_rps;
        if (d_poc < 0 && current->use_delta_flag[idx3]) {
            delta_poc_s0[i] = d_poc;
            used_by_curr_pic_s0[i++] = current->used_by_curr_pic_flag[idx3];
        }

        d_poc = ref_delta_poc_s0[idx4] + delta_rps;
        if (d_poc < 0 && current->use_delta_flag[idx4]) {
            delta_poc_s0[i] = d_poc;
            used_by_curr_pic_s0[i++] = current->used_by_curr_pic_flag[idx4];
        }
    }
    for (; j * 4 < ref->num_negative_pics; j++) {
        d_poc = ref_delta_poc_s0[j] + delta_rps;
        if (d_poc < 0 && current->use_delta_flag[j]) {
            delta_poc_s0[i] = d_poc;
            used_by_curr_pic_s0[i++] = current->used_by_curr_pic_flag[j];
        }
    }
}
