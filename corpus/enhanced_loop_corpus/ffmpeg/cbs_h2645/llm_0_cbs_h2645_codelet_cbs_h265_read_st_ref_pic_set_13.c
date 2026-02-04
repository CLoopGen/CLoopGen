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
extern int delta_poc_s1[16];
extern uint8_t used_by_curr_pic_s1[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased loop nesting depth by splitting the original loop into two nested loops
    // Outer loop iterates over chunks of negative pictures, inner loop processes individual elements in each chunk
    int chunk_size = 4;
    int num_chunks = (ref->num_negative_pics + chunk_size - 1) / chunk_size;
    for (int c = 0; c < num_chunks; c++) {
        int start_j = ref->num_negative_pics - 1 - c * chunk_size;
        int end_j = ref->num_negative_pics - (c + 1) * chunk_size;
        if (end_j < -1) end_j = -1;
        for (j = start_j; j > end_j; j--) {
            if (j >= 0) {
                d_poc = ref_delta_poc_s0[j] + delta_rps;
                if (d_poc > 0 && current->use_delta_flag[j]) {
                    delta_poc_s1[i] = d_poc;
                    used_by_curr_pic_s1[i++] = current->used_by_curr_pic_flag[j];
                }
            }
        }
    }
}
