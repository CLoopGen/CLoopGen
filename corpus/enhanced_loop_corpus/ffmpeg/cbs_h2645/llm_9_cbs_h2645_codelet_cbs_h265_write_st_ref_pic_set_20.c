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

extern int i;
extern  H265RawSTRefPicSet *ref;
extern int d_poc;
extern int ref_delta_poc_s0[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    int upper = (ref->num_negative_pics + 1) & ~1;
    for (i = 0; i < upper; i += step) {
        int adjusted_delta0 = ref->delta_poc_s0_minus1[i] + 1;
        d_poc -= adjusted_delta0;
        ref_delta_poc_s0[i] = d_poc;
        if (i + 1 < ref->num_negative_pics) {
            int adjusted_delta1 = ref->delta_poc_s0_minus1[i + 1] + 1;
            d_poc -= adjusted_delta1;
            ref_delta_poc_s0[i + 1] = d_poc;
        }
    }
}
