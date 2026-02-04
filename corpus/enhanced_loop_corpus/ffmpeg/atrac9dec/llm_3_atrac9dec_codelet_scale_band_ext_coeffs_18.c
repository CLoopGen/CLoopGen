#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct ATRAC9ChannelData {
    int band_ext;
    int q_unit_cnt;
    int band_ext_data[4];
    int32_t scalefactors[31];
    int32_t scalefactors_prev[31];
    int precision_coarse[30];
    int precision_fine[30];
    int precision_mask[30];
    int codebookset[30];
    int32_t q_coeffs_coarse[256];
    int32_t q_coeffs_fine[256];
    float coeffs[256] __attribute__((aligned(32)));
    float prev_win[128] __attribute__((aligned(32)));
} ATRAC9ChannelData;

extern  int at9_q_unit_to_coeff_idx[];
extern ATRAC9ChannelData *c;
extern float sf[6];
extern  int s_unit;
extern  int e_unit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Buffer
    // Precompute all target indices into a temporary buffer and perform indirect access
    // This changes the access pattern from direct nested loops to an indexed flat traversal.
    int idx_buffer[256]; // Conservative size based on max possible coeffs
    int buf_size = 0;

    // Flatten all relevant indices from each q_unit range
    for (int i = s_unit; i < e_unit; i++) {
        const int start = at9_q_unit_to_coeff_idx[i + 0];
        const int end = at9_q_unit_to_coeff_idx[i + 1];
        for (int j = start; j < end; j++) {
            idx_buffer[buf_size++] = j;
        }
    }

    // Perform scaling using indirect access through buffer
    for (int k = 0; k < buf_size; ) {
        int i = s_unit;
        while (i < e_unit && at9_q_unit_to_coeff_idx[i + 1] <= idx_buffer[k]) {
            i++;
        }
        const int scale_idx = i - s_unit;
        // Apply scaling to all coefficients belonging to current unit
        const int current_end = at9_q_unit_to_coeff_idx[i + 1];
        while (k < buf_size && idx_buffer[k] < current_end) {
            c->coeffs[idx_buffer[k]] *= sf[scale_idx];
            k++;
        }
    }
}
