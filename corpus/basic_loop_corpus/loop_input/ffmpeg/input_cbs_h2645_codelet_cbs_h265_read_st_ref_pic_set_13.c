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

    // Initialize ref->num_negative_pics to a reasonable value within [0,16]
    ref->num_negative_pics = 16;

    // Initialize other fields to avoid undefined behavior
    ref->num_positive_pics = 0;
    current->num_negative_pics = 0;
    current->num_positive_pics = 0;
    delta_rps = 1;

    // Initialize ref_delta_poc_s0 with decreasing values to simulate negative deltas
    for (int idx = 0; idx < 16; idx++) {
        ref_delta_poc_s0[idx] = -idx * 5;
    }

    // Initialize current's flags so that some iterations will satisfy the condition
    for (int idx = 0; idx < 16; idx++) {
        current->used_by_curr_pic_flag[idx] = 1;
        current->use_delta_flag[idx] = (idx % 2); // Every other flag set
    }

    // Initialize output tracking index
    i = 0;

    // Ensure arrays used in loop are initialized
    for (int idx = 0; idx < 16; idx++) {
        delta_poc_s1[idx] = 0;
        used_by_curr_pic_s1[idx] = 0;
    }
}