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
extern int ref_delta_poc_s1[16];
extern int delta_poc_s1[16];
extern uint8_t used_by_curr_pic_s1[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Introduce a stride of 2 (access every second element), processing in two passes if needed.
    // This changes access pattern from sequential to strided, which may help expose memory-level parallelism.
    // We simulate a strided traversal by stepping j by 2 each time and handling remainder separately.

    int n = ref->num_positive_pics;
    int stride = 2;
    int d_poc_val;

    // First pass: even indices (0, 2, 4, ...)
    for (j = 0; j < n; j += stride) {
        d_poc_val = ref_delta_poc_s1[j] + delta_rps;
        if (d_poc_val > 0 && current->use_delta_flag[ref->num_negative_pics + j]) {
            delta_poc_s1[i] = d_poc_val;
            used_by_curr_pic_s1[i++] = current->used_by_curr_pic_flag[ref->num_negative_pics + j];
        }
    }

    // Second pass: odd indices (1, 3, 5, ...) to maintain logical correctness
    for (j = 1; j < n; j += stride) {
        d_poc_val = ref_delta_poc_s1[j] + delta_rps;
        if (d_poc_val > 0 && current->use_delta_flag[ref->num_negative_pics + j]) {
            delta_poc_s1[i] = d_poc_val;
            used_by_curr_pic_s1[i++] = current->used_by_curr_pic_flag[ref->num_negative_pics + j];
        }
    }
}
