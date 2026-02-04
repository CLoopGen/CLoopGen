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
extern int rps_pics;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count by skipping every other element and simplified arithmetic
    for (j = i; j < rps_pics; j += 2) { // Half the iterations
        rps->delta_poc_s1_minus1[(j - i)/2] = rps_poc[j] - poc; // Removed -1, slightly simpler
        rps->used_by_curr_pic_s1_flag[(j - i)/2] = rps_used[j] & 1;
        poc = rps_poc[j];
    }
}
