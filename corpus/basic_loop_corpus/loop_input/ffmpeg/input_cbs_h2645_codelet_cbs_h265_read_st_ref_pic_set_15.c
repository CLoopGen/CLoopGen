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

H265RawSTRefPicSet *current;
int i;
int delta_poc_s1[16];
uint8_t used_by_curr_pic_s1[16];

void init_vars() {
    current = (H265RawSTRefPicSet*)malloc(sizeof(H265RawSTRefPicSet));
    if (!current) exit(1);

    current->inter_ref_pic_set_prediction_flag = 1;
    current->delta_idx_minus1 = 0;
    current->delta_rps_sign = 0;
    current->abs_delta_rps_minus1 = 0;
    for (int j = 0; j < 16; j++) {
        current->used_by_curr_pic_flag[j] = j % 2;
        current->use_delta_flag[j] = 1;
    }
    current->num_negative_pics = 0;
    current->num_positive_pics = 16;

    for (int j = 0; j < 16; j++) {
        delta_poc_s1[j] = (j + 1) * 2;
        used_by_curr_pic_s1[j] = (j % 3) != 0;
        current->delta_poc_s0_minus1[j] = 0;
        current->used_by_curr_pic_s0_flag[j] = 0;
        current->delta_poc_s1_minus1[j] = 0;
        current->used_by_curr_pic_s1_flag[j] = 0;
    }
}