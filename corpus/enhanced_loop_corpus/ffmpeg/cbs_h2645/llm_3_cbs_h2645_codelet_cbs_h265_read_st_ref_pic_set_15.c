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
extern int delta_poc_s1[16];
extern uint8_t used_by_curr_pic_s1[16];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access with stride of 2 (interleaved processing)
    int n = current->num_positive_pics;
    int stride = 2;
    int offset;

    // Process even indices first (0, 2, 4, ...)
    for (offset = 0; offset < stride; offset++) {
        for (int j = offset; j < n; j += stride) {
            current->delta_poc_s1_minus1[j] = delta_poc_s1[j] - (j == 0 ? 0 : delta_poc_s1[j - 1]) - 1;
            current->used_by_curr_pic_s1_flag[j] = used_by_curr_pic_s1[j];
        }
    }
}
