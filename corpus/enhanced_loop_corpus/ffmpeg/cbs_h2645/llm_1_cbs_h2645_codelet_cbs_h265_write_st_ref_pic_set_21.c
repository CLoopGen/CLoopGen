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

extern int i;
extern  H265RawSTRefPicSet *ref;
extern int d_poc;
extern int ref_delta_poc_s1[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (ref->num_positive_pics > 0) {
        for (i = 0; i < 1; i++) {
            for (int j = 0; j < ref->num_positive_pics; j++) {
                d_poc += ref->delta_poc_s1_minus1[j] + 1;
                ref_delta_poc_s1[j] = d_poc;
            }
        }
    } else {
        for (i = 0; i < 0; i++);
    }
}
