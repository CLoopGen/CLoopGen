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
int rps_pics;

void init_vars() {
    rps_pics = 16;
    i = 0;
    poc = 240;

    rps_poc = (int*)calloc(rps_pics, sizeof(int));
    rps_used = (int*)calloc(rps_pics, sizeof(int));
    rps = (H265RawSTRefPicSet*)calloc(1, sizeof(H265RawSTRefPicSet));

    for (int idx = 0; idx < rps_pics; idx++) {
        rps_poc[idx] = 240 + idx * 10;
        rps_used[idx] = (idx % 2);
    }
}