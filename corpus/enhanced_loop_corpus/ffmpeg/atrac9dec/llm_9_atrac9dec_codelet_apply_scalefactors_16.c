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
extern  float at9_scalefactor_c[];
extern ATRAC9BlockData *b;
extern  int stereo;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i <= stereo; i++) {
    float *coeffs = b->channel[i].coeffs;
    int total_q_units = b->q_unit_cnt >> 1;
    for (int j = 0; j < total_q_units; j++) {
        const int idx = j << 1;
        const int start = at9_q_unit_to_coeff_idx[idx];
        const int mid = at9_q_unit_to_coeff_idx[idx + 1];
        const int end = at9_q_unit_to_coeff_idx[idx + 2];
        const int scalefactor_low = b->channel[i].scalefactors[idx];
        const int scalefactor_high = b->channel[i].scalefactors[idx + 1];
        const float scale_low = at9_scalefactor_c[scalefactor_low];
        const float scale_high = at9_scalefactor_c[scalefactor_high];

        for (int k = start; k < mid; k++)
            coeffs[k] *= scale_low;
        for (int k = mid; k < end; k++)
            coeffs[k] *= scale_high;
    }
}
}
