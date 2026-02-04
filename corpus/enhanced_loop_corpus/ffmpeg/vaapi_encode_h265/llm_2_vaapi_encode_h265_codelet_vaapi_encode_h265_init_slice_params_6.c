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

extern H265RawSTRefPicSet *rps;
extern int rps_poc[16];
extern int rps_used[16];
extern int i;
extern int j;
extern int poc;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive forward access with index reversal (memory access pattern modified to write in increasing order)
    int offset = i - 1;
    for (j = 0; j < i; j++) {
        int idx = offset - j;  // Reverse the iteration order via index calculation
        rps->delta_poc_s0_minus1[j] = poc - rps_poc[idx] - 1;
        rps->used_by_curr_pic_s0_flag[j] = rps_used[idx];
        if (j == i - 1) poc = rps_poc[idx];  // Final update when last element is processed
    }
}
