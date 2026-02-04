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
    // Allocate rps on heap to allow flexible initialization
    rps = (H265RawSTRefPicSet*)malloc(sizeof(H265RawSTRefPicSet));
    if (!rps) return;

    // Initialize scalar fields
    rps->inter_ref_pic_set_prediction_flag = 1;
    rps->delta_idx_minus1 = 0;
    rps->delta_rps_sign = 0;
    rps->abs_delta_rps_minus1 = 10;
    rps->num_negative_pics = 0;
    
    // Set num_positive_pics to a value that will make loop run long enough (~0.01s)
    // Assume modern CPU can do ~1e9 iterations/sec, so 1e7 iterations ~0.01s
    // But we need to stay within array bounds: used_by_curr_pic_s1_flag[16]
    // So cap at 16, and rely on multiple calls or external factors for timing
    // Instead, ensure full array utilization without overflow
    rps->num_positive_pics = 16;  // Maximum safe value
    
    // Initialize arrays
    for (int j = 0; j < 16; j++) {
        rps->used_by_curr_pic_flag[j] = (j % 2);
        rps->use_delta_flag[j] = 1;
        rps->delta_poc_s0_minus1[j] = j;
        rps->used_by_curr_pic_s0_flag[j] = (j % 3 == 0);
        rps->delta_poc_s1_minus1[j] = j * 2;
        // Make about half of these true to induce branching cost
        rps->used_by_curr_pic_s1_flag[j] = ((j % 2) == 0);
    }

    // Reset counter
    num_pic_total_curr = 0;
}