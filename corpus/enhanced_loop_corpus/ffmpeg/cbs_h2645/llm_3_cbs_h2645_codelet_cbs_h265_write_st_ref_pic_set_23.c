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
extern int j;
extern  H265RawSTRefPicSet *ref;
extern int delta_rps;
extern int d_poc;
extern int ref_delta_poc_s0[16];
extern int delta_poc_s0[16];
extern uint8_t used_by_curr_pic_s0[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (coalesced) memory access via local accumulation buffer
    // We modify the access pattern to first gather all necessary data into local arrays
    // to promote consecutive, predictable memory accesses, then write out in a second loop.
    // This improves potential vectorization and cache locality.

    int temp_deltas[16];
    uint8_t temp_flags[16];
    int count = 0;

    // First pass: gather valid entries using original access pattern
    for (j = 0; j < ref->num_negative_pics; j++) {
        d_poc = ref_delta_poc_s0[j] + delta_rps;
        if (d_poc < 0 && current->use_delta_flag[j]) {
            temp_deltas[count] = d_poc;
            temp_flags[count++] = current->used_by_curr_pic_flag[j];
        }
    }

    // Second pass: write results consecutively (sequential store pattern)
    for (j = 0; j < count; j++) {
        delta_poc_s0[i] = temp_deltas[j];
        used_by_curr_pic_s0[i++] = temp_flags[j];
    }
}
