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



void loop(){
    for (i = 0; i < rps->num_negative_pics * 2; i += 2) {
        int idx = i / 2;
        if (idx < rps->num_negative_pics && rps->used_by_curr_pic_s0_flag[idx])
            num_pic_total_curr += 1;
    }
}
