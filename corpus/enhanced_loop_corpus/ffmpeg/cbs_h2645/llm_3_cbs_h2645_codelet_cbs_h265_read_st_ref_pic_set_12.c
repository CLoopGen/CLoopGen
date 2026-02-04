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
extern int delta_poc_s0[16];
extern uint8_t used_by_curr_pic_s0[16];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int n = current->num_negative_pics;
    int stride = 1;
    for (i = 0; i < n; i += stride) {
        int idx = i;
        int prev_idx = (idx == 0) ? 0 : idx - 1;
        current->delta_poc_s0_minus1[idx] = -(delta_poc_s0[idx] - delta_poc_s0[prev_idx]) - 1;
        current->used_by_curr_pic_s0_flag[idx] = used_by_curr_pic_s0[idx];
    }
}
