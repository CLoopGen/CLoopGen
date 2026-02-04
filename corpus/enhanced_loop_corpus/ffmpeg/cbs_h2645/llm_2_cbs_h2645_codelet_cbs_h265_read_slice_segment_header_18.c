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

extern unsigned int num_pic_total_curr;
extern int i;
extern  H265RawSTRefPicSet *rps;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2, unrolled by factor 2
    // This variant accesses every second element to create a strided pattern.
    uint8_t *used_flag = rps->used_by_curr_pic_s1_flag;
    uint8_t num_pics = rps->num_positive_pics;

    // Handle odd-sized arrays by including last element if needed
    for (i = 0; i < (int)(num_pics & ~1); i += 2) {
        if (used_flag[i])
            ++num_pic_total_curr;
        if (used_flag[i + 1])
            ++num_pic_total_curr;
    }
    if (i < num_pics && used_flag[i])
        ++num_pic_total_curr;
}
