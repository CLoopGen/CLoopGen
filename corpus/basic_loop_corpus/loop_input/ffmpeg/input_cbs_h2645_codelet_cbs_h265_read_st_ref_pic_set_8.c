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

int i;
H265RawSTRefPicSet *ref;
int d_poc;
int ref_delta_poc_s0[16];

void init_vars() {
    ref = (H265RawSTRefPicSet*)malloc(sizeof(H265RawSTRefPicSet));
    if (!ref) exit(1);

    ref->inter_ref_pic_set_prediction_flag = 1;
    ref->delta_idx_minus1 = 0;
    ref->delta_rps_sign = 0;
    ref->abs_delta_rps_minus1 = 0;
    ref->num_negative_pics = 16;
    ref->num_positive_pics = 0;

    for (int j = 0; j < 16; j++) {
        ref->used_by_curr_pic_flag[j] = 1;
        ref->use_delta_flag[j] = 1;
        ref->delta_poc_s0_minus1[j] = 100 + j;
        ref->used_by_curr_pic_s0_flag[j] = 1;
        ref->delta_poc_s1_minus1[j] = 0;
        ref->used_by_curr_pic_s1_flag[j] = 0;
    }

    d_poc = 10000;
}