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

extern H265RawSTRefPicSet *current;
extern int i;
extern int delta_poc_s0[16];
extern uint8_t used_by_curr_pic_s0[16];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < current->num_negative_pics; i++) {
    do {
        current->delta_poc_s0_minus1[i] = -(delta_poc_s0[i] - (i == 0 ? 0 : delta_poc_s0[i - 1])) - 1;
    } while (0);
    do {
        current->used_by_curr_pic_s0_flag[i] = used_by_curr_pic_s0[i];
    } while (0);
}

}
