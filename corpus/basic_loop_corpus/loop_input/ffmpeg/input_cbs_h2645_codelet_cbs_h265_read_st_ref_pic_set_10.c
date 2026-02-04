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
int j;
H265RawSTRefPicSet *ref;
int delta_rps;
int d_poc;
int ref_delta_poc_s1[16];
int delta_poc_s0[16];
uint8_t used_by_curr_pic_s0[16];

void init_vars() {
    // Allocate memory for current and ref
    current = (H265RawSTRefPicSet*)malloc(sizeof(H265RawSTRefPicSet));
    ref = (H265RawSTRefPicSet*)malloc(sizeof(H265RawSTRefPicSet));

    // Initialize current
    current->num_negative_pics = 8;  // must be <= 16
    current->use_delta_flag[8] = 1;
    current->use_delta_flag[9] = 1;
    current->use_delta_flag[10] = 1;
    current->use_delta_flag[11] = 1;
    current->use_delta_flag[12] = 1;
    current->use_delta_flag[13] = 1;
    current->use_delta_flag[14] = 1;
    current->use_delta_flag[15] = 1;
    for (int idx = 0; idx < 16; ++idx) {
        current->used_by_curr_pic_flag[idx] = (idx % 2);
    }

    // Initialize ref
    ref->num_positive_pics = 16;
    for (int idx = 0; idx < 16; ++idx) {
        ref_delta_poc_s1[idx] = -10 + idx * 5;  // negative and positive values
    }

    // Initialize other globals
    delta_rps = 5;
    i = 0;

    // Ensure arrays are zero-initialized to avoid garbage
    for (int idx = 0; idx < 16; ++idx) {
        delta_poc_s0[idx] = 0;
        used_by_curr_pic_s0[idx] = 0;
    }
}