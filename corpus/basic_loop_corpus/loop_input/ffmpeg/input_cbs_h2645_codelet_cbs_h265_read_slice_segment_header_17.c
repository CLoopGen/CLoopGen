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

unsigned int num_pic_total_curr = 0;
int i = 0;
H265RawSTRefPicSet *rps = NULL;

void init_vars() {
    rps = (H265RawSTRefPicSet*)calloc(1, sizeof(H265RawSTRefPicSet));
    if (!rps) exit(1);

    rps->num_negative_pics = 16;
    rps->num_positive_pics = 0;

    for (int j = 0; j < 16; ++j) {
        rps->used_by_curr_pic_flag[j] = 0;
        rps->use_delta_flag[j] = 0;
        rps->delta_poc_s0_minus1[j] = j;
        rps->used_by_curr_pic_s0_flag[j] = (j % 2);
        rps->delta_poc_s1_minus1[j] = 0;
        rps->used_by_curr_pic_s1_flag[j] = 0;
    }

    num_pic_total_curr = 0;
    i = 0;
}