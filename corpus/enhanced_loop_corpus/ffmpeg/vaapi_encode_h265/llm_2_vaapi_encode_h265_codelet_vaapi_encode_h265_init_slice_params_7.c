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



void loop() {
    // Variant 1: Strided memory access with step size of 2, unrolled by factor 2
    // Simulates non-consecutive writes by processing every second element first, then the odd positions
    int stride = 2;
    for (j = i; j < rps_pics; j += stride) {
        int idx = j - i;
        if (j < rps_pics) {
            rps->delta_poc_s1_minus1[idx] = rps_poc[j] - poc - 1;
            rps->used_by_curr_pic_s1_flag[idx] = rps_used[j];
            poc = rps_poc[j];
        }
        int j_next = j + 1;
        if (j_next < rps_pics) {
            int idx_next = j_next - i;
            rps->delta_poc_s1_minus1[idx_next] = rps_poc[j_next] - poc - 1;
            rps->used_by_curr_pic_s1_flag[idx_next] = rps_used[j_next];
            poc = rps_poc[j_next];
        }
    }
}
