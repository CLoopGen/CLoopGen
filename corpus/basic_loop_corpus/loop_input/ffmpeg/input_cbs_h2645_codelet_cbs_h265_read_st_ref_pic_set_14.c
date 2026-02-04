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
int delta_poc_s1[16];
uint8_t used_by_curr_pic_s1[16];

void init_vars() {
    // Allocate memory for current and ref structures
    current = (H265RawSTRefPicSet*)calloc(1, sizeof(H265RawSTRefPicSet));
    ref = (H265RawSTRefPicSet*)calloc(1, sizeof(H265RawSTRefPicSet));

    // Set reasonable values within bounds
    current->num_negative_pics = 8;  // Less than or equal to 16
    current->num_positive_pics = 8;
    ref->num_negative_pics = 8;
    ref->num_positive_pics = 8;  // Must match loop bound

    // Initialize arrays in current and ref
    for (int idx = 0; idx < 16; idx++) {
        current->used_by_curr_pic_flag[idx] = (idx < 12) ? (idx % 2) : 0;
        current->use_delta_flag[idx] = (idx < 12) ? ((idx + 1) % 2) : 0;
    }

    // Initialize ref_delta_poc_s1 and other inputs
    for (int idx = 0; idx < 16; idx++) {
        ref_delta_poc_s1[idx] = (idx < ref->num_positive_pics) ? (idx * 5 + 1) : 0;
    }

    // Initialize delta_rps to a positive value so some conditions pass
    delta_rps = 10;

    // Initialize counters
    i = 0;
    j = 0;

    // Ensure arrays are zeroed
    for (int idx = 0; idx < 16; idx++) {
        delta_poc_s1[idx] = 0;
        used_by_curr_pic_s1[idx] = 0;
    }
}