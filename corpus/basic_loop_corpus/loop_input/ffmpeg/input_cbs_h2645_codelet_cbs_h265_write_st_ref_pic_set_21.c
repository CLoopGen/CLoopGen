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
int ref_delta_poc_s1[16];

void init_vars() {
    ref = (H265RawSTRefPicSet *)malloc(sizeof(H265RawSTRefPicSet));
    if (!ref) {
        exit(1);
    }

    ref->num_positive_pics = 16;
    for (int j = 0; j < 16; j++) {
        ref->delta_poc_s1_minus1[j] = 100 + j;
        ref->used_by_curr_pic_s1_flag[j] = 1;
    }
    d_poc = 1000;
}