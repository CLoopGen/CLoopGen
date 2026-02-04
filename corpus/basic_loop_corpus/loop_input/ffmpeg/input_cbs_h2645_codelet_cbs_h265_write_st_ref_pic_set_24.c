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
int ref_delta_poc_s0[16];
int delta_poc_s1[16];
uint8_t used_by_curr_pic_s1[16];

void init_vars() {
    // Allocate memory for current and ref structures
    current = (H265RawSTRefPicSet*)calloc(1, sizeof(H265RawSTRefPicSet));
    ref = (H265RawSTRefPicSet*)calloc(1, sizeof(H265RawSTRefPicSet));

    // Set meaningful values within safe bounds
    ref->num_negative_pics = 16;  // Max allowed by loop and array sizes

    // Initialize ref_delta_poc_s0 with decreasing negative values
    for (int idx = 0; idx < 16; idx++) {
        ref_delta_poc_s0[idx] = -100 + idx * 10;
    }

    // Set delta_rps to a positive value to trigger condition
    delta_rps = 150;

    // Initialize current's flags so that some conditions pass
    for (int idx = 0; idx < 16; idx++) {
        current->use_delta_flag[idx] = 1;  // Enable all
        current->used_by_curr_pic_flag[idx] = (idx % 2);  // Alternate used flag
    }

    // Initialize output index
    i = 0;

    // Ensure arrays are zero-initialized beyond the logic
    for (int idx = 0; idx < 16; idx++) {
        delta_poc_s1[idx] = 0;
        used_by_curr_pic_s1[idx] = 0;
    }
}