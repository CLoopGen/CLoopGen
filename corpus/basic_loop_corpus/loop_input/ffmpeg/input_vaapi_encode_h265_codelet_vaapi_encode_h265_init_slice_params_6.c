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

H265RawSTRefPicSet *rps;
int *rps_poc;
int *rps_used;
int i;
int j;
int poc;

void init_vars() {
    i = 16;
    poc = 1000;

    rps_poc = (int*)malloc(i * sizeof(int));
    rps_used = (int*)malloc(i * sizeof(int));
    rps = (H265RawSTRefPicSet*)malloc(sizeof(H265RawSTRefPicSet));

    for (int idx = 0; idx < i; idx++) {
        rps_poc[idx] = 1000 - idx * 50;
        rps_used[idx] = (idx % 2);
    }

    rps->num_negative_pics = 0;
    rps->num_positive_pics = 0;
    for (int idx = 0; idx < 16; idx++) {
        rps->used_by_curr_pic_flag[idx] = 0;
        rps->use_delta_flag[idx] = 0;
        rps->delta_poc_s0_minus1[idx] = 0;
        rps->used_by_curr_pic_s0_flag[idx] = 0;
        rps->delta_poc_s1_minus1[idx] = 0;
        rps->used_by_curr_pic_s1_flag[idx] = 0;
    }
}