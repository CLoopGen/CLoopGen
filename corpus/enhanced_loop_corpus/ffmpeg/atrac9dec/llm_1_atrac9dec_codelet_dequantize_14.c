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
extern  float at9_quant_step_coarse[];
extern  float at9_quant_step_fine[];
extern ATRAC9ChannelData *c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < c->q_unit_cnt; i++) {
        const int start = at9_q_unit_to_coeff_idx[i + 0];
        const int end = at9_q_unit_to_coeff_idx[i + 1];
        const float coarse_c = at9_quant_step_coarse[c->precision_coarse[i]];
        const float fine_c = at9_quant_step_fine[c->precision_fine[i]];
        for (int j = start; j < end; j++) {
            float sum = 0.0f;
            sum += c->q_coeffs_coarse[j] * coarse_c;
            sum += c->q_coeffs_fine[j] * fine_c;
            c->coeffs[j] = sum;
        }
    }
    for (int k = 0; k < c->q_unit_cnt; k++) {
        const int s = at9_q_unit_to_coeff_idx[k];
        const int t = at9_q_unit_to_coeff_idx[k + 1];
        if (s >= t) continue;
        const float prev_scale = at9_quant_step_coarse[c->precision_coarse[k]] + at9_quant_step_fine[c->precision_fine[k]];
        for (int m = s; m < t; m++) {
            c->coeffs[m] *= (prev_scale / (at9_quant_step_coarse[c->precision_coarse[k]] + at9_quant_step_fine[c->precision_fine[k]]));
        }
    }
}
