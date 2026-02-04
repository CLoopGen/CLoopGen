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
    // Allocate rps structure
    rps = (H265RawSTRefPicSet*)malloc(sizeof(H265RawSTRefPicSet));
    if (!rps) {
        return;
    }

    // Initialize scalar fields
    rps->inter_ref_pic_set_prediction_flag = 0;
    rps->delta_idx_minus1 = 0;
    rps->delta_rps_sign = 0;
    rps->abs_delta_rps_minus1 = 0;
    rps->num_negative_pics = 0;
    
    // Set num_positive_pics to a value that will make the loop run long enough
    // to take ~0.01 seconds. Assume simple conditionals take ~10 cycles,
    // and modern CPU does ~3GHz -> ~30M iterations per 0.01s.
    // We'll aim for around 20-25 million iterations.
    rps->num_positive_pics = 25000000;

    // Initialize arrays: set all flags to 0 except every other one to 1 to simulate real usage
    for (int j = 0; j < 16; j++) {
        rps->used_by_curr_pic_flag[j] = (j % 2);
        rps->use_delta_flag[j] = (j % 2);
        rps->delta_poc_s0_minus1[j] = j;
        rps->used_by_curr_pic_s0_flag[j] = (j % 2);
        rps->delta_poc_s1_minus1[j] = j + 1;
        rps->used_by_curr_pic_s1_flag[j] = 0; // will set later for larger array
    }

    // For indices beyond 16, we need to extend used_by_curr_pic_s1_flag
    // But since it's fixed size (16), we must ensure we don't exceed bounds.
    // However, num_positive_pics is now 25M which would overflow!
    // So we must reinterpret: likely the array size implies max of 16.
    // Therefore, correct interpretation: num_positive_pics cannot exceed 16.

    // Re-evaluate: the array used_by_curr_pic_s1_flag has size 16 -> max index 15.
    // So num_positive_pics must be <= 16.

    // To achieve 0.01s runtime with small loop, we need external repetition.
    // But problem says "ensure memory access does not go out of bounds"
    // So we must respect array bounds.

    // Therefore: set num_positive_pics to 16 (max legal)
    rps->num_positive_pics = 16;

    // Now initialize used_by_curr_pic_s1_flag so about half are set
    for (int j = 0; j < 16; j++) {
        rps->used_by_curr_pic_s1_flag[j] = (j % 2);  // 8 true values
    }

    // Reset counter
    num_pic_total_curr = 0;
}