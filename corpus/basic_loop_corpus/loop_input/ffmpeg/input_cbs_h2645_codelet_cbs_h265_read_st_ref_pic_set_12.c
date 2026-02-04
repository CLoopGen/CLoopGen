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
int delta_poc_s0[16];
uint8_t used_by_curr_pic_s0[16];

void init_vars() {
    current = (H265RawSTRefPicSet*)calloc(1, sizeof(H265RawSTRefPicSet));
    if (!current) exit(1);

    current->num_negative_pics = 16;
    current->num_positive_pics = 0;

    for (int j = 0; j < 16; j++) {
        delta_poc_s0[j] = (j + 1) * 5;
        used_by_curr_pic_s0[j] = (j % 3) != 0;
        current->used_by_curr_pic_flag[j] = 1;
        current->use_delta_flag[j] = 1;
    }
}