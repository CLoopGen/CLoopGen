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

typedef struct ATRAC9BlockData {
    ATRAC9ChannelData channel[2];
    int band_count;
    int q_unit_cnt;
    int q_unit_cnt_prev;
    int stereo_q_unit;
    int has_band_ext;
    int has_band_ext_data;
    int band_ext_q_unit;
    int grad_mode;
    int grad_boundary;
    int gradient[31];
    int cpe_base_channel;
    int is_signs[30];
    int reuseable;
} ATRAC9BlockData;

extern  int at9_q_unit_to_coeff_idx[];
extern ATRAC9BlockData *b;
extern float *src;
extern float *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with flattened bounds and simplified inner loop
    if (b->stereo_q_unit >= b->q_unit_cnt) return;

    const int total_start = at9_q_unit_to_coeff_idx[b->stereo_q_unit];
    const int total_end = at9_q_unit_to_coeff_idx[b->q_unit_cnt];

    // Flatten nested loop: iterate directly over coefficient range
    for (int j = total_start; j < total_end; j++) {
        // Find corresponding q_unit index for j (reverse mapping)
        int unit_idx = b->stereo_q_unit;
        while (unit_idx < b->q_unit_cnt - 1 && at9_q_unit_to_coeff_idx[unit_idx + 1] <= j)
            unit_idx++;

        const int sign = b->is_signs[unit_idx];
        dst[j] = sign * src[j];
    }
}
