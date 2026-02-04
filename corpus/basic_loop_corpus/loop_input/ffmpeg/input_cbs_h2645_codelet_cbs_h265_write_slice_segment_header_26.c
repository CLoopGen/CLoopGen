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
    // Allocate rps structure on heap to allow initialization
    rps = (H265RawSTRefPicSet*)calloc(1, sizeof(H265RawSTRefPicSet));
    if (!rps) {
        return;
    }

    // Set num_negative_pics to a value that ensures ~0.01s runtime
    // Assume modern CPU does ~1e9 iterations/sec -> ~1e7 in 0.01s
    // Use ~8 million to be safe within 0.01s range
    rps->num_negative_pics = 8000000;  // 8e6 iterations

    // Only allocate what's necessary: we need used_by_curr_pic_s0_flag[num_negative_pics]
    // But the struct declares it as fixed-size [16] -> so maximum allowed is 16
    // Therefore, cap num_negative_pics at 16 to avoid out-of-bounds access
    rps->num_negative_pics = 16;

    // Initialize flags: set half of them to 1 to trigger the increment
    for (int j = 0; j < 16; j++) {
        rps->used_by_curr_pic_s0_flag[j] = (j % 2); // every other flag set
    }

    // Zero out other fields to be safe
    rps->inter_ref_pic_set_prediction_flag = 0;
    rps->delta_idx_minus1 = 0;
    rps->delta_rps_sign = 0;
    rps->abs_delta_rps_minus1 = 0;
    rps->num_positive_pics = 0;
    for (int j = 0; j < 16; j++) {
        rps->used_by_curr_pic_flag[j] = 0;
        rps->use_delta_flag[j] = 0;
        rps->delta_poc_s0_minus1[j] = 0;
        rps->used_by_curr_pic_s1_flag[j] = 0;
        rps->delta_poc_s1_minus1[j] = 0;
    }

    num_pic_total_curr = 0;
}